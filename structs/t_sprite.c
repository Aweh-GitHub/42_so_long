/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sprite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:23:48 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/17 10:29:54 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_sprite	*t_sprite__new(t_asset_img *idle)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	if (sprite == NULL)
		return (NULL);
	sprite->idle = idle;
	return (sprite);
}

void t_sprite__free(t_sprite *sprite)
{
	ft_free(sprite->idle);
	ft_free(sprite);
}
