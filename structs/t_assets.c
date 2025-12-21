/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_assets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:50:54 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/17 10:26:45 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "stdlib.h"
#include "mlx.h"

t_assets	*t_assets__new()
{
	t_assets	*assets;

	assets = malloc(sizeof(t_assets));
	return (assets);
}