/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_player_bodypart.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:15:12 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/20 18:34:18 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	f_behaviour_player_bodypart_update(t_mlx_behaviour *behaviour)
{
	t_game		*game;
	t_entity	*entity;
	t_vec2		origin;
	t_vec2		target;
	double		progress;

	game = behaviour->param_ref_game;
	entity = behaviour->param_ref_entity;
	if (entity->parent == NULL)
		return (0);
	origin = entity->position;
	target = entity->parent->position;
	progress = game->delta_time * PLAYER_BODY_MOV_SPD;
	entity->position = t_vec2__follow(origin, target, PLAYER_BODY_SPC, progress);
	return (0);
}