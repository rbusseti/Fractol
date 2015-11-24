#include "fractol.h"

void    ft_zoom_in(t_env *e, int x, int y)
{
    double  gapx;
    double  gapy;
    double  xi;
    double  yi;

    gapx = fabs(e->zone->x2 - e->zone->x1);
    gapy = fabs(e->zone->y2 - e->zone->y1);
    xi = gapx / e->width * x + e->zone->x1;
    yi = gapy / e->height * y + e->zone->y1;
    e->zone->x1 = xi - (gapx - gapx * e->zone->zlvl) / 2.0;
    e->zone->x2 = xi + (gapx - gapx * e->zone->zlvl) / 2.0;
    e->zone->y1 = yi - (gapy - gapy * e->zone->zlvl) / 2.0;
    e->zone->y2 = yi + (gapy - gapy * e->zone->zlvl) / 2.0;
    e->zone->cmax += e->zone->cmax * e->zone->zlvl * \
        (e->zone->zoom_value / (e->zone->zoom_value + 1));
    e->zone->zoom_value++;
}

void    ft_zoom_out(t_env *e)
{
    double  gapx;
    double  gapy;
    double  xi;
    double  yi;

    gapx = fabs(e->zone->x2 - e->zone->x1);
    gapy = fabs(e->zone->y2 - e->zone->y1);
    xi = gapx / e->width * e->width / 2 + e->zone->x1;
    yi = gapy / e->height * e->height / 2 + e->zone->y1;
    e->zone->x1 = xi - (gapx + gapx * e->zone->zlvl) / 2.0;
    e->zone->x2 = xi + (gapx + gapx * e->zone->zlvl) / 2.0;
    e->zone->y1 = yi - (gapy + gapy * e->zone->zlvl) / 2.0;
    e->zone->y2 = yi + (gapy + gapy * e->zone->zlvl) / 2.0;
    e->zone->cmax -= e->zone->basecmax * e->zone->zlvl;
}

int	ft_mouse_hook(int button, int x, int y, t_env *e)
{
    e->mouse->x = x;
    e->mouse->y = y;
    if (button == SCROLL_UP || button == LCLICK)
        ft_zoom_in(e, x, y);
    else if (button == SCROLL_DW || button == RCLICK)
        ft_zoom_out(e);
    ft_putnbr(e->zone->cmax);
    ft_putchar('\n');
    ft_launch_fractale(e);
    return (0);
}
