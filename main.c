/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:35:15 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/16 09:22:57 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include "so_long.h"
#include <sys/time.h>

int	handle_input(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	(void) game;
	ft_printf("keycode: %d\n", keycode);
	return (0);
}

void	init_hooks(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, on_key_press, game);
	mlx_hook(game->window, 3, 1L << 1, on_key_release, game);
	// mlx_loop_hook(void *mlx_ptr, int (*func)(void *), void *param);
	// mlx_loop_hook(game->mlx, );
}

t_game	*init_game()
{
	t_game	*game;

	game = t_game__new(mlx_init());
	if (game == NULL)
		return (NULL);
	init_hooks(game);
	return (game);
}
int	main(void)
{
	void	*player_img;
	int	w, h;
	t_game	*game;

	game = init_game();
	if (game == NULL)
		return (ERROR);
	player_img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &w, &h);
	if (player_img == NULL)
	{
		ft_printf("impossible de charger l'image\n");
		return (1);
	}
	mlx_loop(game->mlx);
	return (0);
}