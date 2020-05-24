#include <string.h>
#include <stdio.h>
#include "color.h"
#include "pixel.h"
#include "../set.h"
#include "color_map.h"

void color_pixel_with_black_on_white_color_map(pixel *px, fractal_matrix iterations_taken_matrix) {
    rgb_color black = {0, 0, 0};
    rgb_color white = {255, 255, 255};

    int ret;
    point p;

    point_set_from_pixel(&p, *px);

    ret = fractal_matrix_point_belongs_to_mandelbrot_set(p, iterations_taken_matrix);

    if (ret == INSIDE) {
        pixel_set_color(px, black);
        return;
    }

    pixel_set_color(px, white);
}

void color_pixel_with_white_on_black_color_map(pixel *px, fractal_matrix iterations_taken_matrix) {
    rgb_color black = {0, 0, 0};
    rgb_color white = {255, 255, 255};

    int ret;
    point p;

    point_set_from_pixel(&p, *px);

    ret = fractal_matrix_point_belongs_to_mandelbrot_set(p, iterations_taken_matrix);

    if (ret == INSIDE) {
        pixel_set_color(px, white);
        return;
    }

    pixel_set_color(px, black);
}