# include "fractol.h"

void    ft_copy_rgb(int *c, char *img, unsigned char rgb)
{
    char    *pixel;
    int     i;

    i = 0;
    pixel = ft_itoa((int)rgb);
    while (pixel[i] != '\0')
    {
        img[*c] = pixel[i];
        i++;
        *c = *c + 1;
    }
    img[*c] = ' ';
    *c = *c + 1;
    free(pixel);
}

void    ft_convert_to_ppm(t_env *e, int i, char *img)
{
    unsigned char   rgb;
    int             j;
    int             c;

    j = 0;
    c = 0;
    img[c] = '\n';
    c++;
    while (j < e->width)
    {
        img[c] = ' ';
        c++;
        rgb = e->idata->adr[i * e->idata->line + j * e->idata->bpp / 8 + 2];
        ft_copy_rgb(&c, img, rgb);
        rgb = e->idata->adr[i * e->idata->line + j * e->idata->bpp / 8 + 1];
        ft_copy_rgb(&c, img, rgb);
        rgb = e->idata->adr[i * e->idata->line + j * e->idata->bpp / 8];
        ft_copy_rgb(&c, img, rgb);
        j++;
    }
    img[c]= '\0';
}

void    ft_init_image(t_env *e)
{
    if (e->show == 0)
    {
        e->show = 1;
        e->width = WIDTH;
        e->height = HEIGHT;
    }
    else
    {
        e->show = 0;
        e->width = W_WIDTH;
        e->height = W_HEIGHT;
    }
    mlx_destroy_image(e->mlx, e->img);
    e->img = mlx_new_image(e->mlx, e->width, e->height);
    free(e->idata);
    e->idata = ft_get_img_data(e->img);
}

void    ft_save_image(t_env *e)
{
    int     fd;
    char    *info;
    char    *img;
    int     i;

    ft_init_image(e);
    ft_launch_fractale(e);
    info = "P3\n1600 1400\n255";
    fd = open(ft_strjoin("img", ft_itoa(e->img_num)), O_RDWR | O_CREAT, 00755);
    e->img_num++;
    ft_putstr_fd(info, fd);
    i = 0;
    while (i < e->height)
    {
        img = malloc(sizeof(char) * (e->width * 10 * 3));
        ft_convert_to_ppm(e, i, img);
        ft_putstr_fd(img, fd);
        i++;
        free(img);
    }
    close(fd);
    ft_putendl("fichier creer");
    ft_init_image(e);
}
