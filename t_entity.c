/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_entity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:26:49 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/16 09:22:25 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

t_entity	*t_entity__new0(t_mlx_behaviour *behaviour)
{
	t_entity	*entity;

	entity = malloc(sizeof(t_entity));
	entity->behaviour = behaviour;
	return (entity);
}

t_entity	*t_entity__new1(t_mlx_behaviour *behaviour, void *idle)
{
	t_entity	*entity;

	entity = t_entity__new0(behaviour);
	if (entity == NULL)
		return (NULL);
	entity->sprite = t_sprite__new(idle);
	if (entity->sprite == NULL)
		return (ft_free(entity), NULL);
	return (entity);
}

t_entity	*t_entity__new2(t_mlx_behaviour *behaviour, t_sprite *sprite)
{
	t_entity	*entity;

	entity = t_entity__new0(behaviour);
	if (entity == NULL)
		return (NULL);
	entity->sprite = sprite;
	return (entity);
}

void	t_entity__free(t_entity *entity)
{
	t_sprite__free(entity->sprite);
	t_mlx_behaviour__free(entity->behaviour);
	ft_free(entity);
}