#include "fractol.h"

int     ft_key_hook(int keycode, t_env *e)
{
    if (keycode == ESC)
        exit(0);
    return (0);
}
