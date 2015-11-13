#include "fractol.h"

int	ft_loop_hook(t_env *e)
{
    if (e->fract_id == 0)
        ft_mandelbrot(e);
    return (0);
}
