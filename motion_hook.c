#include "fractol.h"

int     ft_motion_hook(int x, int y, t_env *e)
{
    double  cr;
    double  ci;

    if (e->fract_id == 0 || e->motion == 0)
        return (0);
    cr = ((double)x - (e->width / 2.0)) / (e->width / 2.0);
    ci = ((double)y - (e->height / 2.0)) / (e->height / 2.0);
    e->zone->cr = cr;
    e->zone->ci = ci;
    ft_launch_fractale(e);
    return (0);
}
