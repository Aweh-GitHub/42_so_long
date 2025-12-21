/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:35:15 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/21 13:42:44 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include "so_long.h"
#include <sys/time.h>
#include <stdio.h>

int	handle_delta_time(t_game *game)
{
	struct timeval	time_current;
	double			current_seconds;
	double			prev_seconds;

	gettimeofday(&time_current, NULL);
	current_seconds = timeval_to_sec(&time_current);
	prev_seconds = timeval_to_sec(&game->last_timeval);
	game->delta_time = current_seconds - prev_seconds;
	game->last_timeval = time_current;
	return (0);
}

void	handle_behaviour_update(t_game *game)
{
	t_list		*entity_list;
	t_list		*entity_node;
	t_mlx_behaviour	*entity_behaviour;

	entity_list = game->entity_list;
	entity_node = entity_list;
	while (entity_node != NULL)
	{
		entity_behaviour = ((t_entity *)(entity_node->value))->behaviour;
		if (entity_behaviour->f_update != NULL)
			entity_behaviour->f_update(entity_behaviour);
		entity_node = entity_node->next;
	}
}

void handle_behaviour_collision_update(t_game *game)
{
	struct timeval	time_current;
	double			current_sec;
	double			last_collision_sec;
	t_list			*entity_node;
	t_mlx_behaviour	*entity_behaviour;


	gettimeofday(&time_current, NULL);
	current_sec = timeval_to_sec(&time_current);
	if (game->last_collision_timeval.tv_sec != 0)
	{
		last_collision_sec = timeval_to_sec(&game->last_collision_timeval);
		if (current_sec - last_collision_sec < 0.05f)
			return ;
	}

	

	
	entity_node = game->entity_list;
	while (entity_node != NULL)
	{
		entity_behaviour = ((t_entity *)(entity_node->value))->behaviour;
		if (entity_behaviour->f_collision_update != NULL)
			entity_behaviour->f_collision_update(entity_behaviour);
		entity_node = entity_node->next;
	}
	game->last_collision_timeval = time_current;
}

int	f_main_loop(t_game *game)
{
	handle_delta_time(game);
	handle_behaviour_collision_update(game);
	handle_behaviour_update(game);
	render(game);
	return (0);
}

t_game	*init_game()
{
	t_game	*game;

	game = t_game__new(mlx_init());
	if (game == NULL)
		return (NULL);
	game->assets->circle_img = t_asset_img__new(game, "textures/circle128.xpm", 128);
	game->assets->consumbale_apple_img = t_asset_img__new(game, "textures/apple128.xpm", 128);
	init_render(game);
	gettimeofday(&game->last_timeval, NULL);
	mlx_hook(game->window, 2, 1L << 0, on_key_press, game);
	mlx_hook(game->window, 3, 1L << 1, on_key_release, game);
	mlx_loop_hook(game->mlx, f_main_loop, game);
	return (game);
}

int	main(void)
{
	t_game	*game;

	game = init_game();
	if (game == NULL)
		return (ERROR);
	init_spawn(game);
	mlx_loop(game->mlx);
	return (0);
}