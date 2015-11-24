#include "fractol.h"

t_lyap  *ft_init_lyapunov(t_env *e)
{
    t_lyap  *lyap;

    lyap = malloc(sizeof(*lyap));
    lyap->init = 400;
    lyap->iter = 800;
    lyap->x = LYAPX;
    lyap->y = LYAPY;
    lyap->max_result = 1.9;
    lyap->min_result = 10.0;
    if (e->width > e->height)
        lyap->steps = (4 - lyap->y - 0.2) / e->width;
    else
        lyap->steps = (4 - lyap->y) / e->height;
    return (lyap);
}

double  *ft_init_sequence(double a, double b, t_lyap *lyap)
{
    double  *sequence;

    lyap->seq_size = 4;
    sequence = malloc(sizeof(double) * lyap->seq_size);
    sequence[0] = a;
    sequence[1] = b;
    sequence[2] = b;
    sequence[3] = a;
    return (sequence);
}

double  ft_find_exp(t_lyap *lyap, double a, double b)
{
    int     i;
    double  *sequence;
    double  x;
    double  exp;

    i = 0;
    x = 0.5;
    exp = 0;
    sequence = ft_init_sequence(a, b, lyap);
    while (i < lyap->init)
    {
        x = sequence[i % 4] * x * (1.0 - x);
        i++;
    }
    i = 0;
    while (i < lyap->iter)
    {
        x = sequence[i % 4] * x * (1.0 - x);
        exp = exp + (log(fabs(sequence[i % 4] - 2.0 * \
                              sequence[i % 4] * x)) / log(2));
        i++;
    }
    free(sequence);
    return (exp / lyap->iter);
}

void    ft_find_color(double exp, t_env *e, int x, int y, t_lyap *lyap)
{
    double  scale;
    int     i;

    if (exp > 0)
    {
        scale = (lyap->max_result / (e->color->nb / 2));
        i = abs((int)(exp / scale));
        if (i > e->color->nb / 2 - 1)
            i = e->color->nb / 2 - 1;
        if (i < 0)
            i = 0;
        ft_pixel_put_to_image(e->color->palette[i], e->idata, x, y);
    }
    else
    {
        scale = (lyap->min_result / (e->color->nb / 2));
        i = abs((int)(exp / scale));
        if (i > e->color->nb / 2 - 1)
            i = e->color->nb / 2 - 1;
        if (i < 0)
            i = 0;
        ft_pixel_put_to_image(e->color->palette[i + 512], e->idata, x, y);
    }
}

void    ft_lyapunov(t_env *e)
{
    int     i;
    int     j;
    double  exp;
    t_lyap  *lyap;

    i = 0;
    j = 0;
    lyap = ft_init_lyapunov(e);
    while (i < e->width)
    {
        while (j < e->height)
        {
            exp = ft_find_exp(lyap, \
                  i * lyap->steps + lyap->y, j * lyap->steps + lyap->x);
            ft_find_color(exp, e, i, j, lyap);
            j++;
        }
        j = 0;
        i++;
    }
    free(lyap);
    mlx_clear_window(e->mlx, e->win);
    mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
