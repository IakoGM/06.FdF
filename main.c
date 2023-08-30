/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:42:33 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/30 12:13:44 by jakgonza         ###   ########.fr       */
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

int	main(void)
{
	void	*conn;
	void	*win;
	t_data	imagen;
	int		i;
	int		j;

	i = 0;
	conn = mlx_init();
	win = mlx_new_window(conn, 800, 600, "Iakito's Window");
	imagen.img = mlx_new_image(conn, 800, 600);
	imagen.addr = mlx_get_data_addr(imagen.img, &imagen.bits_per_pixel, &imagen.line_length, &imagen.endian);
	while (i < 30)
	{
		j = 0;
		while (j < 30)
		{
			my_mlx_pixel_put(&imagen, 300 + i, 300 + j, 0x00FF0000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(conn, win, imagen.img, 0, 0);
	mlx_loop(conn);
	return (0);
}
