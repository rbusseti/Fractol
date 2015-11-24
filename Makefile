NAME = test

DEBUGNAME = debug

SRC = main.c fract_name.c expose_hook.c key_hook.c mouse_hook.c loop_hook.c \
	mandelbrot.c init.c ft_pixel_put_to_image.c ft_rgb.c \
	ft_make_palette.c init_color.c draw.c julia.c launch_fractale.c \
	motion_hook.c lyapunov.c save_image.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra

INC = -I Headers/ -I libft/includes/

LIB = -L ../minilibx/ -L libft/ -lft -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(LIB) $(INC)

%.o:%.c
	$(CC) $(FLAGS) -c -o $@ $^ $(INC)

debug:
	make -C libft/
	$(CC) -g -o $(DEBUGNAME) $(SRC) $(FLAGS) $(LIB) $(INC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all