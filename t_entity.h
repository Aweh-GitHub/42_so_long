/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_entity.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:30:46 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/15 10:32:08 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENTITY_H
# define T_ENTITY_H

#include "so_long.h"

typedef struct s_entity
{
	t_sprite	*sprite;
	t_vec2		position;
}	t_entity;

t_entity	*t_entity__new0(void);
t_entity	*t_entity__new1(void *idle);
t_entity	*t_entity__new2(t_sprite *sprite);

#endif