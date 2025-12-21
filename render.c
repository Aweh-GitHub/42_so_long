/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:23:15 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/21 13:49:24 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void write_entity_scaled(t_game *game, t_entity *entity)
{
	t_asset_img		*asset;
	double			scale_factor;
	int				screen_x;
	int				screen_y;
	int				draw_width;
	int				draw_height;
	int				x_start;
	int				y_start;
	int				x_end;
	int				y_end;
	int				y;

	if (!entity->sprite || !entity->sprite->idle)
		return ;
	asset = entity->sprite->idle;
	scale_factor = (double)WORLD_PIXELS_PER_UNIT / asset->pixel_per_unit;
	draw_width = (int)(asset->img->width * scale_factor);
	draw_height = (int)(asset->img->height * scale_factor);
	screen_x = (int)(entity->position.x * WORLD_PIXELS_PER_UNIT);
	screen_y = (int)(entity->position.y * WORLD_PIXELS_PER_UNIT);
	x_start = screen_x < 0 ? 0 : screen_x;
	y_start = screen_y < 0 ? 0 : screen_y;
	x_end = (screen_x + draw_width) > WINDOW_W ? WINDOW_W : (screen_x + draw_width);
	y_end = (screen_y + draw_height) > WINDOW_H ? WINDOW_H : (screen_y + draw_height);
	if (x_start >= x_end || y_start >= y_end)
		return ;
	y = y_start;
	while (y < y_end)
	{
		int	src_y = (int)((y - screen_y) / scale_factor);
		int	dst_offset_y = y * game->frame.line_len;
		int	src_offset_y = src_y * asset->img->line_len;

		int	x = x_start;
		while (x < x_end)
		{
			int				src_x = (int)((x - screen_x) / scale_factor);
			unsigned int	color = *(unsigned int *)(asset->img->addr + src_offset_y + src_x * (asset->img->pixel_size / 8));

			if (color != TRANSPARENT)
				*(unsigned int *)(game->frame.addr + dst_offset_y + x * (game->frame.pixel_size / 8)) = color;
			x++;
		}
		y++;
	}
}

int	render(t_game *game)
{
	t_list		*current;
	t_entity	*entity;

	ft_bzero(game->frame.addr, WINDOW_W * WINDOW_H * (game->frame.pixel_size / 8));
	current = game->entity_list;
	while (current)
	{
		entity = (t_entity *)current->value;
		write_entity_scaled(game, entity);
		current = current->next;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->frame.img_mlx, 0, 0);
	return (0);
}

void    init_render(t_game *game)
{
	game->frame.img_mlx = mlx_new_image(game->mlx, WINDOW_W, WINDOW_H);
	game->frame.addr = mlx_get_data_addr(game->frame.img_mlx, &game->frame.pixel_size, &game->frame.line_len, &game->frame.endian);
	game->frame.width = WINDOW_W;
	game->frame.height = WINDOW_H;
}