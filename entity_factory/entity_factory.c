/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_factory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 09:14:36 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/21 13:43:35 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "mlx.h"

static t_entity *create_collider(t_game *game)
{
	t_entity	*collider;

	collider = t_entity__new();
	collider->behaviour = t_mlx_behaviour__new(collider, game, NULL, f_behaviour_collider_collision_update);
	t_list__add0()
	return (collider);
}

static t_entity *create_player_bodypart(t_game *game)
{
	t_entity	*bodypart;

	bodypart = t_entity__new();
	bodypart->behaviour = t_mlx_behaviour__new(bodypart, game, f_behaviour_player_bodypart_update, NULL);
	bodypart->sprite = t_sprite__new(game->assets->circle_img);
	return (bodypart);
}

static t_entity	*create_player(t_game *game)
{
	t_entity	*player;

	player = t_entity__new();
	player->behaviour = t_mlx_behaviour__new(player, game, f_behaviour_player_update, NULL);
	player->sprite = t_sprite__new(game->assets->circle_img);
	t_entity__add_child(player, create_collider(game));
	return (player);
}

static t_entity	*create_consumable(t_game *game)
{
	t_entity	*consumable;

	consumable = t_entity__new();
	consumable->behaviour = t_mlx_behaviour__new(consumable, game, f_behaviour_consumable_update, NULL);
	consumable->sprite = t_sprite__new(game->assets->consumbale_apple_img);
	return (consumable);
}

t_entity	*spawn(t_game *game, t_entity *entity, t_vec2 position)
{
	t_list		*child;

	entity->position = position;
	t_game__add_spawned_entity(game, entity);
	child = entity->childs;
	while (child != NULL)
	{
		t_game__add_spawned_entity(game, (t_entity *) child->value);
		child = child->next;
	}
	return (entity);
}

void	init_spawn(t_game *game)
{
	t_entity	*player;
	
	player = spawn(game, create_player(game), t_vec2__new(0, 0));

	size_t		i;
	t_entity	*prev_bodypart;
	t_entity	*curr_bodypart;

	prev_bodypart = spawn(game, create_player_bodypart(game), t_vec2__new(0, 0));
	t_entity__set_parent(prev_bodypart, player);
	i = 0;
	while (i < 128)
	{
		curr_bodypart = spawn(game, create_player_bodypart(game), t_vec2__new(0, 0));
		t_entity__set_parent(curr_bodypart, prev_bodypart);
		prev_bodypart = curr_bodypart;
		i++;
	}
	spawn(game, create_consumable(game), t_vec2__new(0, 0));
}