/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:43:26 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/20 17:41:45 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include "keycodes.h"
#include "mlx.h"

void	apply_input_pressed(int keycode, t_client_inputs *inputs)
{
	if (keycode == KEY_UP && inputs->inputs[INPUT_UP] == 0 && inputs->axis.y != DIRECTION_DOWN)
	{
		inputs->axis = t_vec2__new(0, DIRECTION_UP);
		inputs->inputs[INPUT_UP] = KEY_PRESSED;
	}
	if (keycode == KEY_DOWN && inputs->inputs[INPUT_DOWN] == 0 && inputs->axis.y != DIRECTION_UP)
	{
		inputs->axis = t_vec2__new(0, DIRECTION_DOWN);
		inputs->inputs[INPUT_DOWN] = KEY_PRESSED;
	}
	if (keycode == KEY_LEFT && inputs->inputs[INPUT_LEFT] == 0 && inputs->axis.x != DIRECTION_RIGHT)
	{
		inputs->axis = t_vec2__new(DIRECTION_LEFT, 0);
		inputs->inputs[INPUT_LEFT] = KEY_PRESSED;
	}
	if (keycode == KEY_RIGHT && inputs->inputs[INPUT_RIGHT] == 0 && inputs->axis.x != DIRECTION_LEFT)
	{
		inputs->axis = t_vec2__new(DIRECTION_RIGHT, 0);
		inputs->inputs[INPUT_RIGHT] = KEY_PRESSED;
	}
}

void	apply_input_released(int keycode, t_client_inputs *inputs)
{
	if (keycode == KEY_UP && inputs->inputs[INPUT_UP] == 1)
		inputs->inputs[INPUT_UP] = KEY_RELEASED;
	if (keycode == KEY_DOWN && inputs->inputs[INPUT_DOWN] == 1)
		inputs->inputs[INPUT_DOWN] = KEY_RELEASED;
	if (keycode == KEY_LEFT && inputs->inputs[INPUT_LEFT] == 1)
		inputs->inputs[INPUT_LEFT] = KEY_RELEASED;
	if (keycode == KEY_RIGHT && inputs->inputs[INPUT_RIGHT] == 1)
		inputs->inputs[INPUT_RIGHT] = KEY_RELEASED;
}

void	input_quit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	ft_free(game);
	exit(EXIT_SUCCESS);
}

int	on_key_press(int keycode, void *uncasted_game)
{
	t_game	*game;

	game = (t_game *) uncasted_game;
	if (keycode == KEY_ESC)
		input_quit(game);
	apply_input_pressed(keycode, game->client_inputs);
	return (0);
}

int	on_key_release(int keycode, void *uncasted_game)
{
	t_game	*game;

	game = (t_game *) uncasted_game;
	apply_input_released(keycode, game->client_inputs);
	return (0);
}