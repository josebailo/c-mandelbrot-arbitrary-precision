#include <string.h>
#include <stdio.h>

#include "../fractal.h"
#include "../set.h"
#include "./color.h"
#include "./color_map.h"
#include "./image.h"

void set_pixel_color(pixel *px, fractal_data_t fractal_data, color_map_name color_map) {
    if (color_map == WHITE_ON_BLACK) {
        color_pixel_with_white_on_black_color_map(px, fractal_data);
        return;
    }

    // Default color_map
    color_pixel_with_black_on_white_color_map(px, fractal_data);
}