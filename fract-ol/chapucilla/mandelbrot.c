/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:12:45 by marcoga2          #+#    #+#             */
/*   Updated: 2025/05/09 17:51:43 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minilibx-linux/mlx.h"
// #include <X11/keysym.h>
#include <stdlib.h>
#include <complex.h> // Para usar números complejos en C
#include <math.h>    // Para fabs() si no usas complex.h
#include <stdio.h>
#include "mlx.h"
#include "mlx_int.h"

#define MALLOC_ERROR	1
#define	WIN_H			800
#define	WIN_W			1400
#define X				50
#define Y				50

typedef struct	s_var
{
	void	*mlx;
	void	*win;
}				t_var;

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;


int	mandelbrot(double complex c, int max_iter)
{
	double complex	z;

	z = 0;
	for (int i = 0; i < max_iter; i++)
	{
		z = z * z + c;
		if (cabs(z) > 2.0)
		{
			return (i); // Se escapó
		}
	}
	return (max_iter); // No se escapó (converge)
}

void *cleanup(t_var var)
{
	mlx_destroy_window(var.mlx, var.win);
	mlx_destroy_display(var.mlx);
	free(var.mlx);
	return (NULL);
}
// 	// Code to create an image and get the related DATA
// 	vars.img.img_ptr = mlx_new_image(vars.mlx,
// 										WIN_H,
// 										WIN_W);
// 	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr,
// 												&vars.img.bits_per_pixel,
// 												&vars.img.line_len,
// 												&vars.img.endian);
// 	//NOT NECESARILY HERE
// typedef struct s_img
// {
// 	void	*img_ptr;
// 	char	*img_pixels_ptr;
// 	int		bits_per_pixel;
// 	int		endian;
// 	int		line_len;
// }				t_img;
void make_map()
{
	//dos bucles while ue genera una array de t_coord en base a WIN_H y WIN_W 
}

void make_complex_map()
{
	//itera sobre el resultado de make map transformando las coordenadas en números complejos (i)
	colorify();
}

void colorify()
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < WIN_H)
	{
		while (j < WIN_W)
		{
			mandelbrot(complex_map[i][j], zoom)
			j++;
		}
		i++;
	}
	
}

int	keyhook(int keysym, t_var *data)
{
	if (keysym == XK_space)
	{
		//change(zoom)
		make_complex_map(data, zoom);
	}



	if (keysym == XK_r)
	{
		color_screen(data, 0xff0000);
	}
	else if (keysym == XK_g)
	{
		color_screen(data, 0xff00);
	}
	else if (keysym == XK_b)
	{
		color_screen(data, 0xff);
	}
	else if (keysym == XK_Escape)
		exit(1);

	// push the READY image to window
	// the last parameters are the offset image-window
	// mlx_put_image_to_window(data->mlx,
	// 						data->win,
	// 						data->img.img_ptr,
	// 						0, 0);

	return 0;
}


/*
 * All the checks for errors like
 *
 * 	~if (vars.mlx == NULL) exit(1);
 *
 * are not written to not clog te code!
 * But u know this stuff is a necessary evil 😂
*/
int	main()
{
	t_var	vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (cleanup(vars));
	vars.win = mlx_new_window(vars.mlx,
								WIN_H,
								WIN_W,
								"My window");
	if (vars.mlx == NULL)
		return (cleanup(vars));

	mlx_key_hook(vars.win,
				keyhook,
				&vars);
				
	mlx_loop(vars.mlx);
}
