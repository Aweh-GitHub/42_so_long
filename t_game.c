/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:19:51 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/15 10:34:05 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "t_game.h"

t_game	*t_game__new(void *mlx)
{
	t_game	*game;

	game = malloc(sizeof(game));
	if (!mlx || !game)
		return (ft_free(game), ft_free(mlx), NULL);
	game->mlx = mlx;
	game->window = mlx_new_window(mlx, WINDOW_W, WINDOW_H, "So Long");
	return (game);
}

void	t_game__free(t_game *game)
{
	if (game == NULL)
		return ;
	ft_free(game->mlx);
	ft_free(game->window);
	ft_free(game);
}