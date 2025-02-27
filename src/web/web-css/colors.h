#pragma once

#include <karm-gfx/colors.h>

// CSS Color Module Level 3
// https://www.w3.org/TR/css-color-3/#html4

namespace Web::Css {

// 4.2.3. ‘transparent’ color keyword
inline constexpr Gfx::Color TRANSPARENT = Gfx::ALPHA;

// 4.3. Extended color keywords
#define FOREACH_COLOR(COLOR)                                    \
    COLOR(ALICEBLUE, aliceblue, 0xF0F8FF)                       \
    COLOR(ANTIQUEWHITE, antiquewhite, 0xFAEBD7)                 \
    COLOR(AQUA, aqua, 0x00FFFF)                                 \
    COLOR(AQUAMARINE, aquamarine, 0x7FFFD4)                     \
    COLOR(AZURE, azure, 0xF0FFFF)                               \
    COLOR(BEIGE, beige, 0xF5F5DC)                               \
    COLOR(BISQUE, bisque, 0xFFE4C4)                             \
    COLOR(BLACK, black, 0x000000)                               \
    COLOR(BLANCHEDALMOND, blanchedalmond, 0xFFEBCD)             \
    COLOR(BLUE, blue, 0x0000FF)                                 \
    COLOR(BLUEVIOLET, blueviolet, 0x8A2BE2)                     \
    COLOR(BROWN, brown, 0xA52A2A)                               \
    COLOR(BURLYWOOD, burlywood, 0xDEB887)                       \
    COLOR(CADETBLUE, cadetblue, 0x5F9EA0)                       \
    COLOR(CHARTREUSE, chartreuse, 0x7FFF00)                     \
    COLOR(CHOCOLATE, chocolate, 0xD2691E)                       \
    COLOR(CORAL, coral, 0xFF7F50)                               \
    COLOR(CORNFLOWERBLUE, cornflowerblue, 0x6495ED)             \
    COLOR(CORNSILK, cornsilk, 0xFFF8DC)                         \
    COLOR(CRIMSON, crimson, 0xDC143C)                           \
    COLOR(CYAN, cyan, 0x00FFFF)                                 \
    COLOR(DARKBLUE, darkblue, 0x00008B)                         \
    COLOR(DARKCYAN, darkcyan, 0x008B8B)                         \
    COLOR(DARKGOLDENROD, darkgoldenrod, 0xB8860B)               \
    COLOR(DARKGRAY, darkgray, 0xA9A9A9)                         \
    COLOR(DARKGREEN, darkgreen, 0x006400)                       \
    COLOR(DARKGREY, darkgrey, 0xA9A9A9)                         \
    COLOR(DARKKHAKI, darkkhaki, 0xBDB76B)                       \
    COLOR(DARKMAGENTA, darkmagenta, 0x8B008B)                   \
    COLOR(DARKOLIVEGREEN, darkolivegreen, 0x556B2F)             \
    COLOR(DARKORANGE, darkorange, 0xFF8C00)                     \
    COLOR(DARKORCHID, darkorchid, 0x9932CC)                     \
    COLOR(DARKRED, darkred, 0x8B0000)                           \
    COLOR(DARKSALMON, darksalmon, 0xE9967A)                     \
    COLOR(DARKSEAGREEN, darkseagreen, 0x8FBC8F)                 \
    COLOR(DARKSLATEBLUE, darkslateblue, 0x483D8B)               \
    COLOR(DARKSLATEGRAY, darkslategray, 0x2F4F4F)               \
    COLOR(DARKSLATEGREY, darkslategrey, 0x2F4F4F)               \
    COLOR(DARKTURQUOISE, darkturquoise, 0x00CED1)               \
    COLOR(DARKVIOLET, darkviolet, 0x9400D3)                     \
    COLOR(DEEPPINK, deeppink, 0xFF1493)                         \
    COLOR(DEEPSKYBLUE, deepskyblue, 0x00BFFF)                   \
    COLOR(DIMGRAY, dimgray, 0x696969)                           \
    COLOR(DIMGREY, dimgrey, 0x696969)                           \
    COLOR(DODGERBLUE, dodgerblue, 0x1E90FF)                     \
    COLOR(FIREBRICK, firebrick, 0xB22222)                       \
    COLOR(FLORALWHITE, floralwhite, 0xFFFAF0)                   \
    COLOR(FORESTGREEN, forestgreen, 0x228B22)                   \
    COLOR(FUCHSIA, fuchsia, 0xFF00FF)                           \
    COLOR(GAINSBORO, gainsboro, 0xDCDCDC)                       \
    COLOR(GHOSTWHITE, ghostwhite, 0xF8F8FF)                     \
    COLOR(GOLD, gold, 0xFFD700)                                 \
    COLOR(GOLDENROD, goldenrod, 0xDAA520)                       \
    COLOR(GRAY, gray, 0x808080)                                 \
    COLOR(GREEN, green, 0x008000)                               \
    COLOR(GREENYELLOW, greenyellow, 0xADFF2F)                   \
    COLOR(GREY, grey, 0x808080)                                 \
    COLOR(HONEYDEW, honeydew, 0xF0FFF0)                         \
    COLOR(HOTPINK, hotpink, 0xFF69B4)                           \
    COLOR(INDIANRED, indianred, 0xCD5C5C)                       \
    COLOR(INDIGO, indigo, 0x4B0082)                             \
    COLOR(IVORY, ivory, 0xFFFFF0)                               \
    COLOR(KHAKI, khaki, 0xF0E68C)                               \
    COLOR(LAVENDER, lavender, 0xE6E6FA)                         \
    COLOR(LAVENDERBLUSH, lavenderblush, 0xFFF0F5)               \
    COLOR(LAWNGREEN, lawngreen, 0x7CFC00)                       \
    COLOR(LEMONCHIFFON, lemonchiffon, 0xFFFACD)                 \
    COLOR(LIGHTBLUE, lightblue, 0xADD8E6)                       \
    COLOR(LIGHTCORAL, lightcoral, 0xF08080)                     \
    COLOR(LIGHTCYAN, lightcyan, 0xE0FFFF)                       \
    COLOR(LIGHTGOLDENRODYELLOW, lightgoldenrodyellow, 0xFAFAD2) \
    COLOR(LIGHTGRAY, lightgray, 0xD3D3D3)                       \
    COLOR(LIGHTGREEN, lightgreen, 0x90EE90)                     \
    COLOR(LIGHTGREY, lightgrey, 0xD3D3D3)                       \
    COLOR(LIGHTPINK, lightpink, 0xFFB6C1)                       \
    COLOR(LIGHTSALMON, lightsalmon, 0xFFA07A)                   \
    COLOR(LIGHTSEAGREEN, lightseagreen, 0x20B2AA)               \
    COLOR(LIGHTSKYBLUE, lightskyblue, 0x87CEFA)                 \
    COLOR(LIGHTSLATEGRAY, lightslategray, 0x778899)             \
    COLOR(LIGHTSLATEGREY, lightslategrey, 0x778899)             \
    COLOR(LIGHTSTEELBLUE, lightsteelblue, 0xB0C4DE)             \
    COLOR(LIGHTYELLOW, lightyellow, 0xFFFFE0)                   \
    COLOR(LIME, lime, 0x00FF00)                                 \
    COLOR(LIMEGREEN, limegreen, 0x32CD32)                       \
    COLOR(LINEN, linen, 0xFAF0E6)                               \
    COLOR(MAGENTA, magenta, 0xFF00FF)                           \
    COLOR(MAROON, maroon, 0x800000)                             \
    COLOR(MEDIUMAQUAMARINE, mediumaquamarine, 0x66CDAA)         \
    COLOR(MEDIUMBLUE, mediumblue, 0x0000CD)                     \
    COLOR(MEDIUMORCHID, mediumorchid, 0xBA55D3)                 \
    COLOR(MEDIUMPURPLE, mediumpurple, 0x9370DB)                 \
    COLOR(MEDIUMSEAGREEN, mediumseagreen, 0x3CB371)             \
    COLOR(MEDIUMSLATEBLUE, mediumslateblue, 0x7B68EE)           \
    COLOR(MEDIUMSPRINGGREEN, mediumspringgreen, 0x00FA9A)       \
    COLOR(MEDIUMTURQUOISE, mediumturquoise, 0x48D1CC)           \
    COLOR(MEDIUMVIOLETRED, mediumvioletred, 0xC71585)           \
    COLOR(MIDNIGHTBLUE, midnightblue, 0x191970)                 \
    COLOR(MINTCREAM, mintcream, 0xF5FFFA)                       \
    COLOR(MISTYROSE, mistyrose, 0xFFE4E1)                       \
    COLOR(MOCCASIN, moccasin, 0xFFE4B5)                         \
    COLOR(NAVAJOWHITE, navajowhite, 0xFFDEAD)                   \
    COLOR(NAVY, navy, 0x000080)                                 \
    COLOR(OLDLACE, oldlace, 0xFDF5E6)                           \
    COLOR(OLIVE, olive, 0x808000)                               \
    COLOR(OLIVEDRAB, olivedrab, 0x6B8E23)                       \
    COLOR(ORANGE, orange, 0xFFA500)                             \
    COLOR(ORANGERED, orangered, 0xFF4500)                       \
    COLOR(ORCHID, orchid, 0xDA70D6)                             \
    COLOR(PALEGOLDENROD, palegoldenrod, 0xEEE8AA)               \
    COLOR(PALEGREEN, palegreen, 0x98FB98)                       \
    COLOR(PALETURQUOISE, paleturquoise, 0xAFEEEE)               \
    COLOR(PALEVIOLETRED, palevioletred, 0xDB7093)               \
    COLOR(PAPAYAWHIP, papayawhip, 0xFFEFD5)                     \
    COLOR(PEACHPUFF, peachpuff, 0xFFDAB9)                       \
    COLOR(PERU, peru, 0xCD853F)                                 \
    COLOR(PINK, pink, 0xFFC0CB)                                 \
    COLOR(PLUM, plum, 0xDDA0DD)                                 \
    COLOR(POWDERBLUE, powderblue, 0xB0E0E6)                     \
    COLOR(PURPLE, purple, 0x800080)                             \
    COLOR(RED, red, 0xFF0000)                                   \
    COLOR(ROSYBROWN, rosybrown, 0xBC8F8F)                       \
    COLOR(ROYALBLUE, royalblue, 0x4169E1)                       \
    COLOR(SADDLEBROWN, saddlebrown, 0x8B4513)                   \
    COLOR(SALMON, salmon, 0xFA8072)                             \
    COLOR(SANDYBROWN, sandybrown, 0xF4A460)                     \
    COLOR(SEAGREEN, seagreen, 0x2E8B57)                         \
    COLOR(SEASHELL, seashell, 0xFFF5EE)                         \
    COLOR(SIENNA, sienna, 0xA0522D)                             \
    COLOR(SILVER, silver, 0xC0C0C0)                             \
    COLOR(SKYBLUE, skyblue, 0x87CEEB)                           \
    COLOR(SLATEBLUE, slateblue, 0x6A5ACD)                       \
    COLOR(SLATEGRAY, slategray, 0x708090)                       \
    COLOR(SLATEGREY, slategrey, 0x708090)                       \
    COLOR(SNOW, snow, 0xFFFAFA)                                 \
    COLOR(SPRINGGREEN, springgreen, 0x00FF7F)                   \
    COLOR(STEELBLUE, steelblue, 0x4682B4)                       \
    COLOR(TAN, tan, 0xD2B48C)                                   \
    COLOR(TEAL, teal, 0x008080)                                 \
    COLOR(THISTLE, thistle, 0xD8BFD8)                           \
    COLOR(TOMATO, tomato, 0xFF6347)                             \
    COLOR(TURQUOISE, turquoise, 0x40E0D0)                       \
    COLOR(VIOLET, violet, 0xEE82EE)                             \
    COLOR(WHEAT, wheat, 0xF5DEB3)                               \
    COLOR(WHITE, white, 0xFFFFFF)                               \
    COLOR(WHITESMOKE, whitesmoke, 0xF5F5F5)                     \
    COLOR(YELLOW, yellow, 0xFFFF00)                             \
    COLOR(YELLOWGREEN, yellowgreen, 0x9ACD32)

#define ITER(NAME, _, VALUE) \
    inline constexpr Gfx::Color NAME = Gfx::Color::fromHex(VALUE);
FOREACH_COLOR(ITER)
#undef ITER

// 4.4. ‘currentColor’ color keyword

struct CurrentColor {
    auto operator<=>(CurrentColor const &) const = default;
};

constexpr inline auto CURRENT_COLOR = CurrentColor{};

using Color = Var<CurrentColor, Gfx::Color>;

} // namespace Web::Css
