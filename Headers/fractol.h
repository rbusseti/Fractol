#ifndef FRACTOL_H

# define FRACTOL_H

# include <math.h>
# include <X11/Xlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft.h"
# include "mlx.h"
# include "const.h"

typedef struct  s_coord
{
    int         x;
    int         y;
}               t_coord;

typedef struct  s_box
{
    double      x1;
    double      x2;
    double      y1;
    double      y2;
}               t_box;

typedef struct  s_zone
{
    double      x1;
    double      x2;
    double      y1;
    double      y2;
    int         cmax;
    int         basecmax;
    double      zlvl;
    int         zoom_value;
    double      cr;
    double      ci;
}               t_zone;

typedef struct  s_idata
{
    char        *adr;
    int         bpp;
    int         line;
    int         edian;
}               t_idata;

typedef struct  s_color
{
    unsigned long   *palette;
    char        **pal_name;
    int         nb;
    int         nb_pal;
    int         current_pal;
    int         current_effect;
    int         nb_effect;
}               t_color;

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
    t_color     *color;
    int         width;
    int         height;
    int         motion;
    int         show;
    int         img_num;
}               t_env;

typedef struct  s_lyap
{
    int         init;
    int         iter;
    double      x;
    double      y;
    double      steps;
    int         seq_size;
    double      max_result;
    double      min_result;
}               t_lyap;

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
void    ft_hook(t_env *e);
int     ft_expose_hook(t_env *e);
int     ft_mouse_hook(int button, int x, int y, t_env *e);
int     ft_key_hook(int keycode, t_env *e);
int     ft_loop_hook(t_env *e);
int     ft_motion_hook(int x, int y, t_env *e);

/*
** INIT
*/
void    ft_init(t_env *e);

/*
** FRACTALE
*/
void    ft_launch_fractale(t_env *e);
void    ft_mandelbrot(t_env *e);
void    ft_julia(t_env *e);
void    ft_lyapunov(t_env *e);

/*
** DRAWING
*/
void    ft_pixel_put_to_image(unsigned long color, t_idata *idata, int y, int x);
unsigned long   ft_rgb(unsigned char r, unsigned char g, unsigned char b);
unsigned long   *ft_make_palette(t_env *e, char *name);
void    ft_init_color(t_env *e);
void    ft_draw(t_env *e, int c, int x, int y);
t_idata *ft_get_img_data(void *img);
void    ft_save_image(t_env *e);

#endif
