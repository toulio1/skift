#pragma once

#include <libgraphic/Color.h>

#define THEME_DEFAULT_BORDER Color::from_rgba_byte(255, 255, 255, 31)
#define THEME_DEFAULT_BACKGROUND Color::from_hex(0x333333)
#define THEME_DEFAULT_MIDDLEGROUND Color::from_hex(0x444444)
#define THEME_DEFAULT_FOREGROUND Color::from_hex(0xFFFFFF)
#define THEME_DEFAULT_FOREGROUND_INACTIVE Color::from_hex(0x888888)
#define THEME_DEFAULT_FOREGROUND_DISABLED Color::from_hex(0x888888)
#define THEME_DEFAULT_SELECTION Color::from_rgba_byte(0, 102, 255, 127)
#define THEME_DEFAULT_SELECTION_INACTIVE Color::from_rgba_byte(136, 136, 136, 63)
#define THEME_DEFAULT_ACCENT Color::from_hex(0x0066FF)
#define THEME_DEFAULT_ACCENT_INACTIVE Color::from_hex(0x444444)
#define THEME_DEFAULT_ANSI_CURSOR Color::from_hex(0xFFB454)
#define THEME_DEFAULT_ANSI_BACKGROUND Color::from_hex(0x0A0E14)
#define THEME_DEFAULT_ANSI_FOREGROUND Color::from_hex(0xB3B1AD)
#define THEME_DEFAULT_ANSI_BLACK Color::from_hex(0x01060E)
#define THEME_DEFAULT_ANSI_RED Color::from_hex(0xEA6C73)
#define THEME_DEFAULT_ANSI_GREEN Color::from_hex(0x91B362)
#define THEME_DEFAULT_ANSI_YELLOW Color::from_hex(0xF9AF4F)
#define THEME_DEFAULT_ANSI_BLUE Color::from_hex(0x53BDFA)
#define THEME_DEFAULT_ANSI_MAGENTA Color::from_hex(0xFAE994)
#define THEME_DEFAULT_ANSI_CYAN Color::from_hex(0x90E1C6)
#define THEME_DEFAULT_ANSI_WHITE Color::from_hex(0xC7C7C7)
#define THEME_DEFAULT_ANSI_BRIGHT_BLACK Color::from_hex(0x686868)
#define THEME_DEFAULT_ANSI_BRIGHT_RED Color::from_hex(0xF07178)
#define THEME_DEFAULT_ANSI_BRIGHT_GREEN Color::from_hex(0xC2D94C)
#define THEME_DEFAULT_ANSI_BRIGHT_YELLOW Color::from_hex(0xFFB454)
#define THEME_DEFAULT_ANSI_BRIGHT_BLUE Color::from_hex(0x59C2FF)
#define THEME_DEFAULT_ANSI_BRIGHT_MAGENTA Color::from_hex(0xFFEE99)
#define THEME_DEFAULT_ANSI_BRIGHT_CYAN Color::from_hex(0x95E6CB)
#define THEME_DEFAULT_ANSI_BRIGHT_WHITE Color::from_hex(0xFFFFFF)

enum ThemeColorRole
{
    THEME_BORDER,
    THEME_BACKGROUND,
    THEME_MIDDLEGROUND,
    THEME_FOREGROUND,
    THEME_FOREGROUND_INACTIVE,
    THEME_FOREGROUND_DISABLED,
    THEME_SELECTION,
    THEME_SELECTION_INACTIVE,
    THEME_ACCENT,
    THEME_ACCENT_INACTIVE,

    THEME_ANSI_CURSOR,
    THEME_ANSI_BACKGROUND,
    THEME_ANSI_FOREGROUND,

    THEME_ANSI_BLACK,
    THEME_ANSI_RED,
    THEME_ANSI_GREEN,
    THEME_ANSI_YELLOW,
    THEME_ANSI_BLUE,
    THEME_ANSI_MAGENTA,
    THEME_ANSI_CYAN,
    THEME_ANSI_WHITE,

    THEME_ANSI_BRIGHT_BLACK,
    THEME_ANSI_BRIGHT_RED,
    THEME_ANSI_BRIGHT_GREEN,
    THEME_ANSI_BRIGHT_YELLOW,
    THEME_ANSI_BRIGHT_BLUE,
    THEME_ANSI_BRIGHT_MAGENTA,
    THEME_ANSI_BRIGHT_CYAN,
    THEME_ANSI_BRIGHT_WHITE,

    __THEME_COLOR_COUNT
};

bool theme_is_dark();

void theme_load(const char *path);

Color theme_get_color(ThemeColorRole role);

void theme_set_color(ThemeColorRole role, Color color);
