#include "fractol.h"

void    ft_print_fract_name(char **name)
{
    int     i;

    i = 0;
    ft_putendl("Invalid parameter.\nList of valid parameters:");
    while (name[i] != NULL)
    {
        ft_putendl(name[i]);
        i++;
    }
    exit(0);
}

void    ft_comp_fract_name(t_env *e, char *name)
{
    int     i;

    i = 0;
    while (e->fract_name[i] != NULL)
    {
        if (ft_strcmp(e->fract_name[i], name) == 0)
        {
            e->fract_id = i;
            return;
        }
        i++;
    }
    ft_print_fract_name(e->fract_name);
}

char    **ft_init_fract_name(void)
{
    char    **name;

    name = malloc(sizeof(char *) * 3);
    name[0] = "mandelbrot";
    name[1] = "julia";
    name[2] = NULL;
    return (name);
}
