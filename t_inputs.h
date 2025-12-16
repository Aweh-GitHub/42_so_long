/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_inputs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:38:15 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/15 11:17:55 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_INPUTS_H
# define T_INPUTS_H

# include "t_vec2.h"

# define PRESSED 1
# define RELEASED 0
# define INPUT_UP 0
# define INPUT_DOWN 1
# define INPUT_LEFT 2
# define INPUT_RIGHT 3

typedef struct s_inputs
{
	int		mov_pressed_inputs[4];
	t_vec2	mov_axis;
}	t_inputs;

int		on_key_press(int keycode, void *uncasted_game);
int		on_key_release(int keycode, void *uncasted_game);

#endif