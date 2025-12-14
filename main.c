/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:35:15 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/14 12:02:02 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx/mlx.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	return (0);
}