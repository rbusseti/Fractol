#include "fractol.h"

int     ft_radiant(t_env *e, int c, int x, int y)
{
    int     i;

    i = c * e->color->nb / e->zone->cmax;
    return (i);
}

void    ft_draw(t_env *e, int c, int x, int y)
{
    int     i;
        
    if (e->color->current_effect == 0)
        i = c * e->color->nb / e->zone->cmax;
    else if (e->color->current_effect == 1)
    {
        if (c % 2 == 0)
            i = c * e->color->nb / e->zone->cmax;
        else
            i = e->color->nb - c * e->color->nb / e->zone->cmax;
    }
    else if (e->color->current_effect == 2)
    {
        i = ft_radiant(e, c, x, y);
    }
    if (c == e->zone->cmax)
        ft_pixel_put_to_image(0x000000, e->idata, x, y);
    else
        ft_pixel_put_to_image(e->color->palette[i], e->idata, x, y);
    
}
