/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:35:15 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/14 12:16:51 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx/mlx.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;

	(void) argc;
	(void) argv;
	mlx = mlx_init();
	if (mlx == NULL)
		return (1);
	window = mlx_new_window(mlx, 640, 480, "So Long");
	void *player_img;
	int w; // Va stocker la largeur du sprite
	int h; // Va stocker la hauteur du sprite

	player_img = mlx_xpm_file_to_image(mlx, "textures/gengar.png", &w, &h);
	mlx_put_image_to_window(mlx, window, player_img, 100, 200);
	mlx_loop(mlx);
	return (0);
}