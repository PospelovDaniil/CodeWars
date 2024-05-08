#include <iostream>

/**
 * Convert A Hex String To RGB
 *
 * When working with color values it can sometimes be useful to extract the individual red, green, and blue (RGB) component values for a color. Implement a function that meets these requirements:
 * Accepts a case-insensitive hexadecimal color string as its parameter (ex. "#FF9933" or "#ff9933")
 * Returns a Map<String, int> with the structure {r: 255, g: 153, b: 51} where r, g, and b range from 0 through 255
 * Note: your implementation does not need to support the shorthand form of hexadecimal notation (ie "#FFF")
 *
 * Example
 * "#FF9933" --> {r: 255, g: 153, b: 51}
 */

typedef struct {
    int r, g, b;
} rgb;

rgb hex_str_to_rgb(const char *hex_str) {
    const long joined = strtol(hex_str + 1, 0, 16);

    rgb res;
    res.r = (joined >> 16) & 0x0000FF;
    res.g = (joined >> 8) & 0x0000FF;
    res.b = joined & 0x0000FF;
    return res;
}

int main()
{
    rgb rgb_;
    rgb_ = hex_str_to_rgb("#0A0B0C");
    return 0;
}
