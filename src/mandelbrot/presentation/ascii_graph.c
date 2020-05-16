#include <stdio.h>

#include "../domain/fractal.h"
#include "../domain/set.h"
#include "ascii_graph.h"

void set_point_character(char *point_char, int x, int y, fractal_matrix iterations_taken_matrix) {

    int ret = fractal_matrix_point_belongs_to_mandelbrot_set(x, y, iterations_taken_matrix);

    if (ret == INSIDE) {
        // Inside Mandelbrot Set
        *point_char = '@';
        return;
    }

    // Outside Mandelbrot Set
    *point_char = ' ';
}