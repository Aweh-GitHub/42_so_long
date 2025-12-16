/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_entity.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:30:46 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/16 09:22:39 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENTITY_H
# define T_ENTITY_H

# include "t_sprite.h"
# include "t_mlx_behaviour.h"

typedef struct s_entity
{
	t_sprite		*sprite;
	t_mlx_behaviour	*behaviour;
	t_vec2			position;
}	t_entity;

t_entity	*t_entity__new0(t_mlx_behaviour *behaviour);
t_entity	*t_entity__new1(t_mlx_behaviour *behaviour, void *idle);
t_entity	*t_entity__new2(t_mlx_behaviour *behaviour, t_sprite *sprite);
void		t_entity__free(t_entity *entity);

#endif