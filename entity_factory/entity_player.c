/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:20:35 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/20 17:39:20 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	handle_movements(t_game *game, t_entity *player)
{
	t_vec2	mov_direction;
	t_vec2	mov;
	double	delta_time;

	delta_time = game->delta_time;
	mov_direction = t_vec2__normalize(game->client_inputs->axis);
	mov = t_vec2__mult2(mov_direction, delta_time * PLAYER_MOV_SPD);
	player->position = t_vec2__add0(player->position, mov);
}

int	f_behaviour_player_update(t_mlx_behaviour *behaviour)
{
	t_game		*game;
	t_entity	*player;

	game = behaviour->param_ref_game;
	player = behaviour->param_ref_entity;
	(void)game;
	(void)player;
	handle_movements(game, player);
	return (0);
}

