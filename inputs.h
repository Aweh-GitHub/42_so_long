/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:38:15 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/15 10:39:28 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

# include "t_game.h"

int		on_key_press(int keycode, void *uncasted_game);
int		on_key_release(int keycode, void *uncasted_game);

void	input_quit(t_game *game);

#endif