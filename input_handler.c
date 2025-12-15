/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:43:26 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/15 10:00:20 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "keycodes_metal.h"

int	on_key_press(int keycode, void *uncasted_game)
{
	t_game	*game;

	game = (t_game *) uncasted_game;
	ft_printf("[ON_KEY_PRESS] keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		input_quit(game);
	return (0);
}

int	on_key_release(int keycode, void *uncasted_game)
{
	t_game	*game;

	game = (t_game *) uncasted_game;
	(void) game;
	ft_printf("[ON_KEY_RELEASE] keycode: %d\n", keycode);
	return (0);
}