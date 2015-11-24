#include "fractol.h"

unsigned long   *ft_neptune(void)
{
    unsigned long   *palette;
    int             i;

    i = 0;
    palette = malloc(sizeof(*palette) * 256 * 4);
    while (i < 256)
    {
        palette[i] = ft_rgb(255 - i, 255, 255);
        palette[i + 256] =  ft_rgb(0, 255 - i, 255);
        palette[i + 512] =  ft_rgb(i, 0, 255);
        palette[i + 768] =  ft_rgb(255 - i, 0, 255 - i);
        i++;
    }
    return (palette);
}

unsigned long   *ft_volcano(void)
{
    unsigned long   *palette;
    int             i;

    i = 0;
    palette = malloc(sizeof(*palette) * 256 * 4);
    while (i < 256)
    {
        palette[i] = ft_rgb(i, 0, 0);
        palette[i + 256] =  ft_rgb(255, i, 0);
        palette[i + 512] =  ft_rgb(255, 255 - i, 0);
        palette[i + 768] =  ft_rgb(255 - i, 0, 0);
        i++;
    }
    return (palette);
}

unsigned long   *ft_sky_and_lava(void)
{
    unsigned long   *palette;
    int             i;

    i = 0;
    palette = malloc(sizeof(*palette) * 256 * 10);
    while (i < 256)
    {
        palette[i] = ft_rgb(255, 255, 255 - i);
        palette[i + 256] =  ft_rgb(255 - i, 255 - i, i);
        palette[i + 512] = ft_rgb(i, i / 2, 0);
        palette[i + 768] =  ft_rgb(255 - i, 127 + i / 2, i);
        palette[i + 1024] = ft_rgb(255 -i, i, i);
        palette[i + 1260] =  ft_rgb(i, 255 - i, i);
        palette[i + 1516] = ft_rgb( 0, 0, i);
        palette[i + 1772] =  ft_rgb(0, i, 255 - i);
        palette[i + 2028] = ft_rgb(i, 255, 0);
        palette[i + 2284] =  ft_rgb(255 -i, 255, 0);
        i++;
    }
    return (palette);
}

unsigned long   *ft_emerald_forest(void)
{
    unsigned long   *palette;
    int             i;

    i = 0;
    palette = malloc(sizeof(*palette) * 256 * 4);
    while (i < 256)
    {
        palette[i] = ft_rgb(0, i, 0);
        palette[i + 256] =  ft_rgb(0, 255 - i, 0 + i / 2);
        palette[i + 512] =  ft_rgb(0, i, 128 - i / 2);
        palette[i + 768] =  ft_rgb(0, 255 - i, 0);
        i++;
    }
    return (palette);
}

unsigned long   *ft_make_palette(t_env *e, char *name)
{
    unsigned long   *palette;

    if (ft_strcmp(name, "neptune_dawn") == 0)
    {
        palette = ft_neptune();
        e->color->nb = 1023;
    }
    else if (ft_strcmp(name, "volcano") == 0)
    {
        palette = ft_volcano();
        e->color->nb = 1023;
    }
    else if (ft_strcmp(name, "sky_and_lava") == 0)
    {
        palette = ft_sky_and_lava();
        e->color->nb = 2559;
    }
    else if (ft_strcmp(name, "emerald_forest") == 0)
    {
        palette = ft_emerald_forest();
        e->color->nb = 2560;
    }
    return (palette);
}
