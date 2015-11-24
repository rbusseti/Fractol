# include "fractol.h"

void    ft_hook(t_env *e)
{
    mlx_expose_hook(e->win, &ft_expose_hook, e);
    mlx_mouse_hook(e->win, &ft_mouse_hook, e);
    mlx_key_hook(e->win, &ft_key_hook, e);
    mlx_hook(e->win, MotionNotify, PointerMotionMask, ft_motion_hook, e);
    mlx_loop(e->mlx);
}

int     main(int argc, char **argv)
{
    t_env   e;

    e.mlx = mlx_init();
    e.fract_name = ft_init_fract_name();
    if (argc != 2)
        ft_print_fract_name(e.fract_name);
    ft_comp_fract_name(&e, argv[1]);
    if (e.fract_id == 1)
    {
        e.win = mlx_new_window(e.mlx, WIDTH / 2, HEIGHT / 2, "Fractol");
        e.img = mlx_new_image(e.mlx, WIDTH / 2, HEIGHT / 2);
    }
    else
    {
        e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Fractol");
        e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
    }
    ft_init(&e);
    ft_launch_fractale(&e);
    ft_hook(&e);
    return (0);
}
