/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sprite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:23:48 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/15 10:35:08 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "t_sprite.h"

t_sprite	*t_sprite__new(void *idle)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	if (sprite == NULL)
		return (NULL);
	sprite->idle = idle;
	return (sprite);
}