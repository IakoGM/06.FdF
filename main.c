/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:42:33 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/30 13:57:24 by jakgonza         ###   ########.fr       */
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
	int		fd;
	int		counter;
    char    *printer;

    counter = 0;
	printer = "";
	i = 0;
	fd = open("test_maps/42.fdf", O_RDONLY);
	if (fd == -1)
	{
		printf("No se ha podido abrir el archivo\n");
		return (0);
	}
	while (printer != NULL)
	{
		printer = get_next_line(fd);
		if (printer == NULL)
		{
			free(printer);
			break ;
		}
		counter++;
		printf("%d : %s\n", counter, printer);
		free(printer);
	}
	close(fd);
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
