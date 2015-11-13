# include "fractol.h"

void    ft_pixel_put_to_image(unsigned long color, t_idata *idata, int y, int x)
{
    unsigned char   r;
    unsigned char   g;
    unsigned char   b;

    r = ((color & 0xFF0000) >> 16);
    g = ((color & 0xFF00) >> 8);
    b = ((color & 0xFF));

    idata->adr[x * idata->line + y * idata->bpp / 8] = b;
    idata->adr[x * idata->line + y * idata->bpp / 8 + 1] = g;
    idata->adr[x * idata->line + y * idata->bpp / 8 + 2] = r;
}
