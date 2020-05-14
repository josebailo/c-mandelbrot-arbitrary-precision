#ifndef C_MANDELBROT_ARBITRARY_PRECISION_PPM_IMAGE_FILE_H
#define C_MANDELBROT_ARBITRARY_PRECISION_PPM_IMAGE_FILE_H

#include "../domain/fractal.h"

void render_and_write_out_image(char *filename, fractal_resolution resolution, int *iterations_taken_matrix);

#endif //C_MANDELBROT_ARBITRARY_PRECISION_PPM_IMAGE_FILE_H