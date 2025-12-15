/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:55:32 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/15 09:59:54 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft/libft.h"

void	input_quit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	ft_free(game);
	exit(EXIT_SUCCESS);
}