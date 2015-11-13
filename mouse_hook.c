#include "fractol.h"

void    ft_zoom_in(t_env *e, int x, int y)
{
    double  gapx;
    double  gapy;
    double  xi;
    double  yi;

    gapx = fabs(e->zone->x2 - e->zone->x1);
    gapy = fabs(e->zone->y2 - e->zone->y1);
    xi = gapx / WIDTH * x + e->zone->x1;
    yi = gapy / HEIGHT * y + e->zone->y1;
    e->zone->x1 = xi - (gapx - gapx * e->zone->zlvl) / 2.0;
    e->zone->x2 = xi + (gapx - gapx * e->zone->zlvl) / 2.0;
    e->zone->y1 = yi - (gapy - gapy * e->zone->zlvl) / 2.0;
    e->zone->y2 = yi + (gapy - gapy * e->zone->zlvl) / 2.0;
    e->zone->cmax += e->zone->cmax * e->zone->zlvl;
}

int	ft_mouse_hook(int button, int x, int y, t_env *e)
{
    e->mouse->x = x;
    e->mouse->y = y;
    if (button == SCROLL_UP || button == SCROLL_DW)
        ft_zoom_in(e, x, y);
    ft_mandelbrot(e);
    return (0);
}
