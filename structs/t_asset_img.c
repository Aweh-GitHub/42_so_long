/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_asset_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:19:36 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/20 17:15:12 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>
#include "mlx.h"

t_asset_img	*t_asset_img__new(t_game *game, char *path, double ppu)
{
	t_asset_img	*asset;

	asset = malloc(sizeof(t_asset_img));
	if (asset == NULL)
		return (NULL);
	asset->img = malloc(sizeof(t_img));
	if (asset->img == NULL)
	{
		free(asset);
		return (NULL);
	}
	asset->img->img_mlx = mlx_xpm_file_to_image(game->mlx, path, &asset->img->width, &asset->img->height);
	if (asset->img->img_mlx == NULL)
		ft_printf("error: xpm file loading failed, ensure path is correct\n");
	asset->img->addr = mlx_get_data_addr(asset->img->img_mlx, &asset->img->pixel_size, &asset->img->line_len, &asset->img->endian);
	asset->width = asset->img->width;
	asset->height = asset->img->height;
	asset->pixel_per_unit = ppu;
	return (asset);
}

void	t_asset_img__free(t_asset_img *asset)
{
	ft_free(asset->img);
	ft_free(asset);
}