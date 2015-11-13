# include "fractol.h"

t_mand  *ft_init_mandelbrot(t_env *e)
{
    t_mand  *man;

    man = malloc(sizeof(*man));
    man->zoomx = WIDTH / (e->zone->x2 - e->zone->x1);
    man->zoomy = HEIGHT / (e->zone->y2 - e->zone->y1);
    return (man);
}

unsigned long    ft_choose_color(int cmax, int c)
{
    unsigned long   color;
    unsigned char   r;
    unsigned char   g;
    unsigned char   b;

    r = 0;
    g = 0;
    b = 0;
    if (c == cmax)
        color = 0x000000;
    else
    {
        if (c < cmax * 1 / 3)
            b = c * 255 / cmax;
        else if (c < cmax * 2 / 3)
            g = c * 255 / cmax;
        else
            r = c * 255 / cmax;
        color = ((r << 16) & 0xff0000) | ((g << 8) & 0xff00) | ((b & 0xff));
    }
    return (color);
}

void    ft_browse_column(t_env *e, t_mand *man, int i)
{
    int             j;
    int             c;
    double          tmp;
    double          sqzr;
    double          sqzi;
    unsigned long   color;

    j = 0;
    while (j < HEIGHT)
    {
        man->cr = i / man->zoomx  + e->zone->x1;
        man->ci = j / man->zoomy  + e->zone->y1;
        man->zr = 0;
        man->zi = 0;
        sqzr = man->zr * man->zr;
        sqzi = man->zi * man->zi;
        c = 0;
        while (sqzr + sqzi <= 4 && c < e->zone->cmax)
        {
            tmp = man->zr;
            man->zr = sqzr - sqzi + man->cr;
            man->zi = man->zi *tmp + man->zi * tmp + man->ci;
            sqzr = man->zr * man->zr;
            sqzi = man->zi * man->zi;
            c++;
        }
        color = ft_choose_color(e->zone->cmax, c);
        ft_pixel_put_to_image(color, e->idata, i, j);
        j++;
    }
}

void    ft_mandelbrot(t_env *e)
{
    t_mand  *man;
    int     i;

    man = ft_init_mandelbrot(e);
    i = 0;
    while (i < WIDTH)
    {
        ft_browse_column(e, man, i);
        i++;
    }
    mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
    free(man);
}
