/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_behaviour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 09:15:54 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/16 09:18:17 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "t_mlx_behaviour.h"

t_mlx_behaviour	*t_mlx_behaviour__new(void (*f_loop)(t_game *))
{
	t_mlx_behaviour	*behaviour;

	behaviour = malloc(sizeof(t_mlx_behaviour));
	if (behaviour == NULL)
		return (NULL);
	behaviour->f_loop = f_loop;
	return (behaviour);
}

void	t_mlx_behaviour__free(t_mlx_behaviour *behaviour)
{
	ft_free(behaviour);
}