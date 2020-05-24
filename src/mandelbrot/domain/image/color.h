#ifndef C_MANDELBROT_ARBITRARY_PRECISION_COLOR_H
#define C_MANDELBROT_ARBITRARY_PRECISION_COLOR_H

#define COLOR_CHAR_SIZE sizeof(char)
#define RBG_COLOR_CHAR_SIZE 3 * COLOR_CHAR_SIZE

typedef char *char_rgb_color;

typedef struct {
    int r, g, b;
} rgb_color;

#endif //C_MANDELBROT_ARBITRARY_PRECISION_COLOR_H