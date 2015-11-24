# include "fractol.h"

void    ft_launch_fractale(t_env *e)
{
    if (e->fract_id == 0)
        ft_mandelbrot(e);
    else if (e->fract_id == 1)
        ft_julia(e);
    else if (e->fract_id == 2)
        ft_lyapunov(e);
    if (e->show == 1)
    {
        mlx_clear_window(e->mlx, e->win);
        mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
    }
}
