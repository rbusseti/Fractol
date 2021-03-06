# include "fractol.h"

t_mand  *ft_init_mandelbrot(t_env *e)
{
    t_mand  *man;

    man = malloc(sizeof(*man));
    man->zoomx = e->width / (e->zone->x2 - e->zone->x1);
    man->zoomy = e->height / (e->zone->y2 - e->zone->y1);
    return (man);
}

void    ft_browse_column(t_env *e, t_mand *man, int i)
{
    int             j;
    int             c;
    double          tmp;
    double          sqzr;
    double          sqzi;

    j = 0;
    while (j < e->height)
    {
        man->cr = i / man->zoomx  + e->zone->x1;
        man->ci = j / man->zoomy  + e->zone->y1;
        man->zr = 0;
        man->zi = 0;
        sqzr = man->zr * man->zr;
        sqzi = man->zi * man->zi;
        c = 0;
        while ((sqzr + sqzi <= 4 && sqzr + sqzi >= -4) && c < e->zone->cmax)
        {
            tmp = man->zr;
            man->zr = sqzr - sqzi + man->cr;
            man->zi = man->zi * tmp + man->zi * tmp + man->ci;
            sqzr = man->zr * man->zr;
            sqzi = man->zi * man->zi;
            c++;
        }
        ft_draw(e, c, i, j);
        j++;
    }
}

void    ft_mandelbrot(t_env *e)
{
    t_mand  *man;
    int     i;

    man = ft_init_mandelbrot(e);
    i = 0;
    while (i < e->width)
    {
        ft_browse_column(e, man, i);
        i++;
    }
    free(man);
}
