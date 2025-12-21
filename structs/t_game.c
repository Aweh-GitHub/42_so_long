/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:19:51 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/21 12:37:01 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../so_long.h"

void	t_game__add_spawned_entity(t_game *game, t_entity *entity)
{
	if (entity->is_spawned)
		return ;
	entity->is_spawned = TRUE;
	ft_lstadd_back(&(game->entity_list), t_list__new(entity));
}

t_game	*t_game__new(void *mlx)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!mlx || !game)
		return (ft_free(game), ft_free(mlx), NULL);
	game->mlx = mlx;
	game->window = mlx_new_window(mlx, WINDOW_W, WINDOW_H, "So Long");
	game->client_inputs = malloc(sizeof(t_client_inputs));
	game->assets = t_assets__new();
	return (game);
}

void	t_game__free(t_game *game)
{
	if (game == NULL)
		return ;
	ft_free(game->mlx);
	ft_free(game->window);
	ft_free(game->client_inputs);
	ft_free(game);
}