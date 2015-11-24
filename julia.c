# include "fractol.h"

t_mand  *ft_init_julia(t_env *e)
{
    t_mand  *man;

    man = malloc(sizeof(*man));
    man->zoomx = e->width / (e->zone->x2 - e->zone->x1);
    man->zoomy = e->height / (e->zone->y2 - e->zone->y1);
    man->cr = e->zone->cr;
    man->ci = e->zone->ci;
    return (man);
}

void    ft_browse_jcolumn(t_env *e, t_mand *man, int i)
{
    int             j;
    int             c;
    double          tmp;
    double          sqzr;
    double          sqzi;

    j = 0;
    while (j < e->height)
    {
        man->zr = i / man->zoomx  + e->zone->x1;
        man->zi = j / man->zoomy  + e->zone->y1;
        sqzr = man->zr * man->zr;
        sqzi = man->zi * man->zi;
        c = 0;
        while (sqzr + sqzi <= 2 && c < e->zone->cmax)
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

void    ft_julia(t_env *e)
{
    t_mand  *man;
    int     i;

    man = ft_init_julia(e);
    i = 0;
    while (i < e->width)
    {
        ft_browse_jcolumn(e, man, i);
        i++;
    }
    free(man);

}
