#pragma once

#include <karm-io/bscan.h>
#include <karm-logger/logger.h>
#include <karm-media/font.h>

namespace Ttf {

struct Cmap : public Io::BChunk {
    static constexpr Str SIG = "cmap";

    struct Table {
        u16 platformId;
        u16 encodingId;
        u16 type;

        Bytes slice;

        Io::BScan begin() const {
            return slice;
        }

        Media::Glyph _glyphIdForType4(Rune r) const {
            u16 segCountX2 = begin().skip(6).nextU16be();
            u16 segCount = segCountX2 / 2;

            for (usize i = 0; i < segCount; i++) {
                auto s = begin().skip(14);

                u16 endCode = s.skip(i * 2).peekU16be();

                if (r >= endCode)
                    continue;

                // + 2 for reserved padding
                u16 startCode = s.skip(segCountX2 + 2).peekU16be();

                if (r < startCode)
                    break;

                u16 idDelta = s.skip(segCountX2).peekI16be();
                u16 idRangeOffset = s.skip(segCountX2).peekU16be();

                if (idRangeOffset == 0) {
                    return Media::Glyph((r + idDelta) & 0xFFFF);
                }

                auto offset = idRangeOffset + (r - startCode) * 2;
                return Media::Glyph(s.skip(offset).nextU16be());
            }

            logWarn("ttf: Glyph not found for rune {x}", r);
            return Media::Glyph(0);
        }

        Media::Glyph _glyphForType12(Rune r) const {
            auto s = begin().skip(12);
            u32 nGroups = s.nextU32be();

            for (u32 i = 0; i < nGroups; i++) {
                u32 startCode = s.nextU32be();
                u32 endCode = s.nextU32be();
                u32 glyphOffset = s.nextU32be();

                if (r < startCode)
                    break;

                if (r > endCode)
                    continue;

                if (r >= startCode and r <= endCode) {
                    return Media::Glyph((r - startCode) + glyphOffset);
                }
            }

            logWarn("ttf: glyph not found for rune {x}", r);
            return Media::Glyph(0);
        }

        Media::Glyph glyphIdFor(Rune r) const {
            if (type == 4) {
                return _glyphIdForType4(r);
            } else if (type == 12) {
                return _glyphForType12(r);
            } else {
                return Media::Glyph(0);
            }
        }
    };

    auto iterTables() {
        auto s = begin();
        s.skip(2);
        usize numTables = s.nextU16be();

        return Iter{[this, s, i = 0uz, numTables]() mutable -> Opt<Table> {
            if (i == numTables) {
                return NONE;
            }

            u16 platformId = s.nextU16be();
            u16 encodingId = s.nextU16be();
            u32 offset = s.nextU32be();
            auto slice = sub(_slice, offset, _slice.len());
            u16 type = Io::BScan{slice}.nextU16be();
            i++;

            return Table{platformId, encodingId, type, slice};
        }};
    }
};

} // namespace Ttf
