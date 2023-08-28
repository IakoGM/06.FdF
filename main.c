/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:42:33 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/28 18:12:10 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// 
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*inicio;
	void	*ventana;
	t_data	imagen;

	inicio = mlx_init();
	ventana = mlx_new_window(inicio, 1920, 1080, "Iakito's Window");
	imagen.img = mlx_new_image(inicio, 1920, 1080);
	imagen.addr = mlx_get_data_addr(imagen.img, &imagen.bits_per_pixel, &imagen.line_length, &imagen.endian);
	my_mlx_pixel_put(&imagen, 500, 500, 0x00FF0000);
	my_mlx_pixel_put(&imagen, 504, 500, 0x00FF0000);
	my_mlx_pixel_put(&imagen, 508, 500, 0x00FF0000);
	my_mlx_pixel_put(&imagen, 512, 500, 0x00FF0000);
	my_mlx_pixel_put(&imagen, 516, 500, 0x00FF0000);
	my_mlx_pixel_put(&imagen, 520, 500, 0x00FF0000);
	my_mlx_pixel_put(&imagen, 524, 500, 0x00FF0000);
	mlx_put_image_to_window(inicio, ventana, imagen.img, 0, 0);
	mlx_loop(inicio);
	return (0);
}
