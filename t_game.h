/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:32:28 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/15 15:34:29 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GAME_H
# define T_GAME_H

# include "t_vec2.h"
# include "t_inputs.h"

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_inputs	*inputs;
	t_list		*entities;

}	t_game;

t_game	*t_game__new(void *mlx);
void	t_game__free(t_game *game);

#endif