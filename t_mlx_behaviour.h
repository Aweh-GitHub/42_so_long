/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_behaviour.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 09:00:28 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/16 09:26:02 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MLX_BEHAVIOUR_H
# define T_MLX_BEHAVIOUR_H

# include "t_game.h"

typedef struct s_mlx_behaviour
{
	void	(*f_loop)(t_entity *entity, t_game *game);
}	t_mlx_behaviour;

t_mlx_behaviour	*t_mlx_behaviour__new(void (*f_loop)(t_game *));
void			t_mlx_behaviour__free(t_mlx_behaviour *behaviour);

#endif