#include <stdio.h>
#include <string.h>

#include "../domain/image/color.h"
#include "../domain/fractal.h"
#include "../domain/image/image.h"
#include "../domain/set.h"
#include "ppm_image_file.h"

void print_ppm_image_header(FILE *fp, fractal_resolution resolution) {
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d %d\n", resolution.width, resolution.height, 255);
}

void print_ppm_image_pixels(FILE *fp, fractal_matrix iterations_taken_matrix) {
    char *color = malloc(RBG_COLOR_SIZE);

    int x, y, num_iter_for_pixel;
    int width = iterations_taken_matrix.resolution.width;
    int height = iterations_taken_matrix.resolution.height;
    pixel px;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            pixel_set(&px, x, y);
            set_pixel_color(color, px, iterations_taken_matrix);
            fwrite(color, 1, RBG_COLOR_SIZE, fp);
        }
    }

    free(color);
}

void render_and_write_out_image(char *filename, fractal_matrix iterations_taken_matrix) {
    FILE *fp;

    fp = fopen(filename, "wb");

    print_ppm_image_header(fp, iterations_taken_matrix.resolution);
    print_ppm_image_pixels(fp, iterations_taken_matrix);

    fclose(fp);
}