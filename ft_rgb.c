#include "fractol.h"

unsigned long   ft_rgb(unsigned char r, unsigned char g, unsigned char b)
{
    unsigned long color;

    color = ((r << 16) & 0xff0000) | ((g << 8) & 0xff00) | ((b & 0xff));
    return (color);
}
