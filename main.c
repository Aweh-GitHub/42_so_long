/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:35:15 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/14 16:59:47 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx/mlx.h"
#include "libft/libft.h"
#include "libmlx/mlx_int.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;
	t_img	*player_img;
	int	w, h;

	(void) argc;
	(void) argv;
	mlx = mlx_init();
	if (mlx == NULL)
		return (1);
	window = mlx_new_window(mlx, 640, 480, "So Long");
	player_img = mlx_xpm_file_to_image(mlx, "textures/gengar_walk.xpm", &w, &h);
	if (player_img == NULL)
	{
		ft_printf("impossible de charger l'image\n");
		return (1);
	}
	mlx_put_image_to_window(mlx, window, player_img, 100, 200);
	mlx_loop(mlx);
	return (0);
}