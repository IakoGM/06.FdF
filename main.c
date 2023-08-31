/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:42:33 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/31 09:05:12 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// Con esta instruccion se determina el offset, el lugar y la longitud del pixel
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// Con esta otra, se castea a unsigned int* y se le asigna el color
	*(unsigned int*)dst = color;
}

// Algoritmo de Breseham
void ft_bresenham(t_data imagen, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1) {
        printf("(%d, %d)\n", x0, y0);
        int err2 = 2 * err;
        if (err2 > -dy)
		{
            err -= dy;
            x0 += sx;
        }
        if (err2 < dx)
		{
            err += dx;
            y0 += sy;
        }
		my_mlx_pixel_put(&imagen, x0, y0, 0x00FF0000);
    }
}

int	main(void)
{
	void	*conn;
	void	*win;
	t_data	imagen;

	int x0 = 300, y0 = 300;
    int x1 = 250, y1 = 120;
	
	conn = mlx_init();
	win = mlx_new_window(conn, 800, 600, "Iakito's Window");
	imagen.img = mlx_new_image(conn, 800, 600);
	imagen.addr = mlx_get_data_addr(imagen.img, &imagen.bits_per_pixel, &imagen.line_length, &imagen.endian);
	ft_bresenham(imagen, x0, y0, x1, y1);
	mlx_put_image_to_window(conn, win, imagen.img, 0, 0);
	mlx_loop(conn);
	return (0);
}


		// my_mlx_pixel_put(&imagen, x, y, 0x00FF0000);
