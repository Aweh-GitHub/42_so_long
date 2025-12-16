/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:43:26 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/15 11:29:54 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "keycodes.h"
#include "mlx.h"

void	apply_input_pressed(int keycode, t_inputs *inputs)
{
	if (keycode == KEY_UP && inputs->mov_pressed_inputs[INPUT_UP] == 0)
	{
		inputs->mov_axis.y += 1;
		inputs->mov_pressed_inputs[INPUT_UP] = PRESSED;
	}
	if (keycode == KEY_DOWN && inputs->mov_pressed_inputs[INPUT_DOWN] == 0)
	{
		inputs->mov_axis.y += -1;
		inputs->mov_pressed_inputs[INPUT_DOWN] = PRESSED;
	}
	if (keycode == KEY_LEFT && inputs->mov_pressed_inputs[INPUT_LEFT] == 0)
	{
		inputs->mov_axis.x += -1;
		inputs->mov_pressed_inputs[INPUT_LEFT] = PRESSED;
	}
	if (keycode == KEY_RIGHT && inputs->mov_pressed_inputs[INPUT_RIGHT] == 0)
	{
		inputs->mov_axis.x += 1;
		inputs->mov_pressed_inputs[INPUT_RIGHT] = PRESSED;
	}
}

void	apply_input_released(int keycode, t_inputs *inputs)
{
	if (keycode == KEY_UP && inputs->mov_pressed_inputs[INPUT_UP] == 1)
	{
		inputs->mov_axis.y += -1;
		inputs->mov_pressed_inputs[INPUT_UP] = RELEASED;
	}
	if (keycode == KEY_DOWN && inputs->mov_pressed_inputs[INPUT_DOWN] == 1)
	{
		inputs->mov_axis.y += 1;
		inputs->mov_pressed_inputs[INPUT_DOWN] = RELEASED;
	}
	if (keycode == KEY_LEFT && inputs->mov_pressed_inputs[INPUT_LEFT] == 1)
	{
		inputs->mov_axis.x += 1;
		inputs->mov_pressed_inputs[INPUT_LEFT] = RELEASED;
	}
	if (keycode == KEY_RIGHT && inputs->mov_pressed_inputs[INPUT_RIGHT] == 1)
	{
		inputs->mov_axis.x += -1;
		inputs->mov_pressed_inputs[INPUT_RIGHT] = RELEASED;
	}
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
	ft_printf("[ON_KEY_PRESS] keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		input_quit(game);
	apply_input_pressed(keycode, game->inputs);
	ft_printf("game_mov: (%d;%d)", game->inputs->mov_axis.x, game->inputs->mov_axis.y);
	return (0);
}

int	on_key_release(int keycode, void *uncasted_game)
{
	t_game	*game;

	game = (t_game *) uncasted_game;
	ft_printf("[ON_KEY_RELEASE] keycode: %d\n", keycode);
	apply_input_released(keycode, game->inputs);
	ft_printf("game_mov: (%d;%d)", game->inputs->mov_axis.x, game->inputs->mov_axis.y);
	return (0);
}