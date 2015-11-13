# include "fractol.h"

t_idata *ft_get_img_data(void *img)
{
    t_idata *idata;

    idata = malloc(sizeof(*idata));
    idata->adr = mlx_get_data_addr(img, &(idata->bpp), \
                                   &(idata->line), &(idata->edian));
    return (idata);
}

t_zone  *ft_init_zone(t_env *e)
{
    t_zone  *zone;

    zone = malloc(sizeof(*zone));
    if (e->fract_id == 0)
    {
        zone->x1 = -2.1;
        zone->x2 = 0.6;
        zone->y1 = -1.2;
        zone->y2 = 1.2;
        zone->cmax = 50;
        zone->zlvl = 0.9;
    }
    return (zone);
}

void    ft_init(t_env *e)
{
    e->mouse = malloc(sizeof(t_mand));
    e->zone = ft_init_zone(e);
    e->idata = ft_get_img_data(e->img);
}
