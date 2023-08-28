/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:42:33 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/28 16:20:33 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main(void)
{
	void	*inicio;
	void	*ventana;

	inicio = mlx_init();
	ventana = mlx_new_window(inicio, 600, 600, "Iakito's Window");
	mlx_loop(inicio);
	return 0;
}
