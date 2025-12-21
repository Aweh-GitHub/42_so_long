/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_behaviour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 09:15:54 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/20 18:27:00 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../so_long.h"

t_mlx_behaviour	*t_mlx_behaviour__new(t_entity *param_ref_entity, t_game *param_ref_game, int (*f_update)(t_mlx_behaviour *), int (*f_collision_update)(t_mlx_behaviour *))
{
	t_mlx_behaviour	*behaviour;

	behaviour = malloc(sizeof(t_mlx_behaviour));
	if (behaviour == NULL)
		return (NULL);
	behaviour->param_ref_entity = param_ref_entity;
	behaviour->param_ref_game = param_ref_game;
	behaviour->f_update = f_update;
	behaviour->f_collision_update = f_collision_update;
	return (behaviour);
}

void	t_mlx_behaviour__free(t_mlx_behaviour *behaviour)
{
	ft_free(behaviour);
}