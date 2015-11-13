#ifndef FRACTOL_H

# define FRACTOL_H

# include <math.h>

# include "libft.h"
# include "mlx.h"
# include "const.h"

typedef struct  s_coord
{
    int         x;
    int         y;
}               t_coord;

typedef struct  s_zone
{
    double      x1;
    double      x2;
    double      y1;
    double      y2;
    double      cmax;
    double      zlvl;
}               t_zone;

typedef struct  s_idata
{
    char        *adr;
    int         bpp;
    int         line;
    int         edian;
}               t_idata;

typedef struct  s_env
{
    void        *mlx;
    void        *win;
    void        *img;
    char        **fract_name;
    int         fract_id;
    t_coord     *mouse;
    t_zone      *zone;
    t_idata     *idata;
}               t_env;

typedef struct  s_mand
{
    double      zoomx;
    double      zoomy;
    double      cr;
    double      ci;
    double      zr;
    double      zi;
}               t_mand;


/*
** FRACTALE NAME
*/
char    **ft_init_fract_name(void);
void    ft_print_fract_name(char **name);
void    ft_comp_fract_name(t_env *e, char *name);

/*
** HOOK
*/
int     ft_expose_hook(t_env *e);
int     ft_mouse_hook(int button, int x, int y, t_env *e);
int     ft_key_hook(int keycode, t_env *e);
int     ft_loop_hook(t_env *e);

/*
** INIT
*/
void    ft_init(t_env *e);

/*
** MANDELBROT
*/
void    ft_mandelbrot(t_env *e);

/*
** DRAWING
*/
void    ft_pixel_put_to_image(unsigned long color, t_idata *idata, int y, int x);

#endif
