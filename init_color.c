#include "fractol.h"

void    ft_init_color(t_env *e)
{
    t_color *color;

    color = malloc(sizeof(*color));
    color->nb_pal = 4;
    color->pal_name = malloc(sizeof(char *) * (color->nb_pal));
    color->pal_name[0] = ft_strdup("neptune_dawn");
    color->pal_name[1] = ft_strdup("volcano");
    color->pal_name[2] = ft_strdup("sky_and_lava");
    color->pal_name[3] = ft_strdup("emerald_forest");

    color->current_pal = 0;
    color->current_effect = 0;
    color->nb_effect = 3;
    e->color = color;
    e->color->palette = ft_make_palette(e, color->pal_name[0]);
}
