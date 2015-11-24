#include "fractol.h"

void    ft_change_palette(int dir, t_env *e)
{
    int     i;

    i = dir + e->color->current_pal;
    if (i >= 0 && i < e->color->nb_pal)
    {
        free(e->color->palette);
        e->color->palette = ft_make_palette(e, e->color->pal_name[i]);
        e->color->current_pal += dir;
        ft_launch_fractale(e);
    }
}

void    ft_change_effect(int dir, t_env *e)
{
    int     i;

    i = dir + e->color->current_effect;
    if (i >= 0 && i < e->color->nb_effect)
    {
        e->color->current_effect = i;
        ft_launch_fractale(e);
    }
}

void    ft_change_motion(t_env *e)
{
    e->motion = 0;
    mlx_destroy_image(e->mlx, e->img);
    mlx_destroy_window(e->mlx, e->win);
    e->width = e->width * 2;
    e->height = e->height * 2;
    e->win = mlx_new_window(e->mlx, e->width, e->height, "fractol");
    e->img = mlx_new_image(e->mlx, e->width, e->height);
    free(e->idata);
    e->idata = ft_get_img_data(e->img);
    e->zone->basecmax = BASE_CMAX;
    e->zone->cmax = BASE_CMAX;
    ft_launch_fractale(e);
    ft_hook(e);
}

int     ft_key_hook(int keycode, t_env *e)
{
    if (keycode == ESC)
        exit(0);
    else if (keycode == LEFT)
        ft_change_palette(-1, e);
    else if (keycode == RIGHT)
        ft_change_palette(1, e);
    else if (keycode == UP)
        ft_change_effect(1, e);
    else if (keycode == DOWN)
        ft_change_effect(-1, e);
    else if (keycode == PLUS)
        e->zone->cmax += BASE_CMAX * (e->zone->zoom_value);
    else if (keycode == MINUS && e->zone->cmax > 10 * (e->zone->zoom_value))
        e->zone->cmax -= BASE_CMAX * (e->zone->zoom_value);
    else if (keycode == DIV)
        e->zone->cmax -= BASE_CMAX * (e->zone->zoom_value) / 10;
    else if (keycode == MULT)
        e->zone->cmax += BASE_CMAX * (e->zone->zoom_value) / 10;
    else if (keycode == ENTER)
        ft_launch_fractale(e);
    else if (keycode == MOTION && e->motion == 1)
        ft_change_motion(e);
    else if (keycode == PRINT)
        ft_save_image(e);
    ft_putnbr(keycode);
    ft_putchar('\n');
    return (0);
}
