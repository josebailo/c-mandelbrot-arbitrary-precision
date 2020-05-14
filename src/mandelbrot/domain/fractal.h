#ifndef C_MANDELBROT_ARBITRARY_PRECISION_FRACTAL_H
#define C_MANDELBROT_ARBITRARY_PRECISION_FRACTAL_H

#include "acb.h"
#include "ztile.h"

typedef struct {
    int width;
    int height;
} fractal_resolution;

/**
 * Matrix[width][height] with number of Mandelbrot formula iterations needed for each pixel to diverge.
 * -1 for point/pixel inside Mandelbrot Set.
 */
typedef struct {
    fractal_resolution resolution;
    int *data;
} fractal_matrix;

void fractal_matrix_init(fractal_matrix *iterations_taken_matrix, fractal_resolution resolution);

void fractal_matrix_clean(fractal_matrix *iterations_taken_matrix);

/**
 * For points inside Mandelbrot Set it returns MAX_ITERATIONS
 * For points outside it returns number of iterations needed to diverge.
 * @param fractal_resolution resolution
 * @param max_iterations
 * @param prec
 * @param iterations_taken_matrix
 */
void calculate_points(
        ztile tile, fractal_resolution resolution,
        int max_iterations,
        slong prec,
        int *iterations_taken_matrix,
        fractal_matrix *iterations_taken_matrix_copy
);

/**
 * Iteration taken matrix is flipped horizontally, that's is to say y pixel coordinates increase from bottom to top.
 * For standard graphics format (used in PPM format) (0,0) pixel coordinates is the left top corner of the image.
 */
int get_iterations_taken_for_point(
        int x, int y,
        int width, int height, int *iterations_taken_matrix
);

#endif //C_MANDELBROT_ARBITRARY_PRECISION_FRACTAL_H