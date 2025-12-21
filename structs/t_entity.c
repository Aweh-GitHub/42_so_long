/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_entity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:26:49 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/21 12:38:54 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

t_entity	*t_entity__new(void)
{
	t_entity	*entity;

	entity = malloc(sizeof(t_entity));
	entity->behaviour = NULL;
	entity->sprite = NULL;
	return (entity);
}

void	t_entity__free(t_entity *entity)
{
	t_sprite__free(entity->sprite);
	t_mlx_behaviour__free(entity->behaviour);
	ft_free(entity);
}

void	t_entity__set_parent(t_entity *child, t_entity *parent)
{
	child->parent = parent;
	t_list__add1(&(parent->childs), child);
}

void	t_entity__add_child(t_entity *parent, t_entity *child)
{
	child->parent = parent;
	t_list__add1(&(parent->childs), child);
}
