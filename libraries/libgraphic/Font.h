#pragma once

#include <libgraphic/Bitmap.h>
#include <libsystem/unicode/Codepoint.h>

typedef struct
{
    Codepoint codepoint;
    Rectangle bound;
    Vec2i origin;
    int advance;
} Glyph;

typedef struct
{
    Bitmap *bitmap;

    Glyph default_glyph;
    Glyph *glyph;
} Font;

Font *font_create(const char *name);

void font_destroy(Font *font);

bool font_has_glyph(Font *font, Codepoint codepoint);

Glyph *font_glyph(Font *font, Codepoint codepoint);

int font_measure_string(Font *font, const char *str);
