/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_entity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:26:49 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/15 10:41:11 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

t_entity	*t_entity__new0(void)
{
	t_entity	*entity;

	entity = malloc(sizeof(t_entity));
	return (entity);
}

t_entity	*t_entity__new1(void *idle)
{
	t_entity	*entity;

	entity = t_entity__new0();
	if (entity == NULL)
		return (NULL);
	entity->sprite = t_sprite__new(idle);
	if (entity->sprite == NULL)
		return (ft_free(entity), NULL);
	return (entity);
}

t_entity	*t_entity__new2(t_sprite *sprite)
{
	t_entity	*entity;

	entity = t_entity__new0();
	if (entity == NULL)
		return (NULL);
	entity->sprite = sprite;
	return (entity);
}

