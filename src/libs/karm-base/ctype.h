#pragma once

#include "rune.h"

namespace Karm {

/* --- Check Identity ------------------------------------------------------- */

constexpr bool isAscii(Rune rune) {
    return rune <= 0x7F;
}

constexpr bool isAsciiDigit(Rune rune) {
    return rune >= '0' and rune <= '9';
}

constexpr bool isAsciiLower(Rune rune) {
    return rune >= 'a' and rune <= 'z';
}

constexpr bool isAsciiUpper(Rune rune) {
    return rune >= 'A' and rune <= 'Z';
}

constexpr bool isAsciiAlpha(Rune rune) {
    return isAsciiLower(rune) or isAsciiUpper(rune);
}

constexpr bool isAsciiAlphaNum(Rune rune) {
    return isAsciiAlpha(rune) or isAsciiDigit(rune);
}

constexpr bool isBinDigit(Rune rune) {
    return rune == '0' or rune == '1';
}

constexpr bool isOctDigit(Rune rune) {
    return rune >= '0' and rune <= '7';
}

constexpr bool isDecDigit(Rune rune) {
    return rune >= '0' and rune <= '9';
}

constexpr bool isHexDigit(Rune rune) {
    return isDecDigit(rune) or (rune >= 'a' and rune <= 'f') or (rune >= 'A' and rune <= 'F');
}

constexpr bool isAsciiBlank(Rune rune) {
    return rune == ' ' or rune == '\t';
}

constexpr bool isAsciiSpace(Rune rune) {
    return rune == ' ' or (rune >= '\t' and rune <= '\r');
}

constexpr bool isAsciiPunct(Rune rune) {
    return (rune >= '!' and rune <= '/') or (rune >= ':' and rune <= '@') or
           (rune >= '[' and rune <= '`') or (rune >= '{' and rune <= '~');
}

constexpr bool isAsciiGraph(Rune rune) {
    return rune >= '!' and rune <= '~';
}

constexpr bool isAsciiPrint(Rune rune) {
    return rune >= ' ' and rune <= '~';
}

constexpr bool isAsciiC0Control(Rune rune) {
    return rune <= 0x20;
}

constexpr bool isAsciiControl(Rune rune) {
    return isAsciiC0Control(rune) or rune == 0x7F;
}

constexpr bool isUnicode(Rune rune) {
    return rune <= 0x10FFFF;
}

constexpr bool isUnicodeControl(Rune rune) {
    return isAsciiC0Control(rune) or (rune >= 0x7E and rune <= 0x9F);
}

constexpr bool isUnicodeSurrogate(Rune rune) {
    return rune >= 0xD800 and rune <= 0xDFFF;
}

constexpr bool isUnicodeScalar(Rune rune) {
    return isUnicode(rune) and not isUnicodeSurrogate(rune);
}

constexpr bool isUnicodeNonCharacter(Rune rune) {
    return isUnicode(rune) and
           ((rune >= 0xFDD0 and rune <= 0xFDEF) or
            ((rune & 0xFFFE) == 0xFFFE) or
            ((rune & 0xFFFF) == 0xFFFF));
}

/* --- Rune Conversion ------------------------------------------------------ */

constexpr Rune toAsciiLower(Rune rune) {
    if (isAsciiUpper(rune))
        return rune + 0x20;

    return rune;
}

constexpr Rune toAsciiUpper(Rune rune) {
    if (isAsciiLower(rune))
        return rune - 0x20;

    return rune;
}

/* --- Rune Parsing --------------------------------------------------------- */

constexpr Rune parseAsciiDecDigit(Rune rune) {
    if (isDecDigit(rune))
        return rune - '0';

    panic("invalid decimal digit");
}

constexpr Rune parseAsciiHexDigit(Rune rune) {
    rune = toAsciiLower(rune);

    if (isDecDigit(rune))
        return rune - '0';

    if (rune >= 'a' and rune <= 'f')
        return rune - 'a' + 10;

    panic("invalid hexadecimal digit");
}

} // namespace Karm
