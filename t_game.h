/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:32:28 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/15 10:41:04 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_list	*entities;

}	t_game;

t_game	*t_game__new(void *mlx);
void	t_game__free(t_game *game);

#endif