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
    }
    else if (e->fract_id == 1)
    {
        zone->x1 = -1;
        zone->x2 = 1;
        zone->y1 = -1.2;
        zone->y2 = 1.2;
        zone->cr = 0;
        zone->cr = 0;
    }
    zone->basecmax = BASE_CMAX;
    if (e->fract_id == 1)
        zone->basecmax = BASE_CMAX / 10;
    zone->cmax = zone->basecmax;
    zone->zlvl = 0.9;
    zone->zoom_value = 1;
    return (zone);
}

void    ft_init(t_env *e)
{
    e->mouse = malloc(sizeof(t_mand));    
    e->zone = ft_init_zone(e);
    e->idata = ft_get_img_data(e->img);
    if (e->fract_id == 1)
    {
        e->width = WIDTH / 2;
        e->height = HEIGHT / 2;
    }
    else
    {
        e->width = WIDTH;
        e->height = HEIGHT;
    }
    if (e->fract_id == 1)
        e->motion = 1;
    else
        e->motion = 0;
    e->show = 1;
    e->img_num = 0;
    ft_init_color(e);
}
