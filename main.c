# include "fractol.h"

void    ft_hook(t_env *e)
{
    mlx_expose_hook(e->win, &ft_expose_hook, e);
    mlx_mouse_hook(e->win, &ft_mouse_hook, e);
    mlx_key_hook(e->win, &ft_key_hook, e);
    mlx_loop(e->mlx);
}

void    ft_lauch_fractale(t_env *e)
{
    if (e->fract_id == 0)
        ft_mandelbrot(e);
}

int     main(int argc, char **argv)
{
    t_env   e;

    e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Fractol");
    e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
    e.fract_name = ft_init_fract_name();
    if (argc != 2)
        ft_print_fract_name(e.fract_name);
    ft_comp_fract_name(&e, argv[1]);
    ft_init(&e);
    ft_lauch_fractale(&e);
    ft_hook(&e);
    return (0);
}
