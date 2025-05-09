NAME = mandelbrot
SRCS = mandelbrot.c

# Rutas a los headers de MiniLibX
INCLUDE = -Imlx -Imlx_linux

# Bibliotecas estáticas de MiniLibX (archivos .a)
MLX_LIBS = \
	mlx/libmlx.a \
	mlx_linux/libmlx_Linux.a

# Dependencias de X11 y matemáticas
DEPS = -lXext -lX11 -lm

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(MLX_LIBS) $(DEPS) -o $(NAME)

clean:
	rm -f $(NAME)

.PHONY: all clean
