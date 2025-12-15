/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sprite.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:34:22 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/15 10:35:16 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SPRITE_H
# define T_SPRITE_H

typedef struct s_sprite
{
	void	*idle;
}	t_sprite;

t_sprite	*t_sprite__new(void *idle);

#endif