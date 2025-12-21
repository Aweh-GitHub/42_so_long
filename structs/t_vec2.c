/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vec2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:39:56 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/20 17:06:23 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_vec2	t_vec2__new(double x, double y)
{
	t_vec2	value;

	value.x = x;
	value.y = y;
	return (value);
}

t_vec2	t_vec2__add0(t_vec2 vec_src, t_vec2 vec_add)
{
	vec_src.x += vec_add.x;
	vec_src.y += vec_add.y;
	return (vec_src);
}

t_vec2	t_vec2__add1(t_vec2 vec, double x, double y)
{
	vec.x += x;
	vec.y += y;
	return (vec);
}

t_vec2	t_vec2__add2(t_vec2 vec, double add)
{
	vec.x += add;
	vec.y += add;
	return (vec);
}

t_vec2	t_vec2__sub0(t_vec2 vec_src, t_vec2 vec_sub)
{
	vec_src.x += vec_sub.x;
	vec_src.y += vec_sub.y;
	return (vec_src);
}

t_vec2	t_vec2__sub1(t_vec2 vec, double x, double y)
{
	vec.x -= x;
	vec.y -= y;
	return (vec);
}

t_vec2	t_vec2__sub2(t_vec2 vec, double sub)
{
	vec.x -= sub;
	vec.y -= sub;
	return (vec);
}

t_vec2	t_vec2__mult0(t_vec2 vec_src, t_vec2 vec_add)
{
	vec_src.x *= vec_add.x;
	vec_src.y *= vec_add.y;
	return (vec_src);
}

t_vec2	t_vec2__mult1(t_vec2 vec, double x, double y)
{
	vec.x *= x;
	vec.y *= y;
	return (vec);
}

t_vec2	t_vec2__mult2(t_vec2 vec, double mult)
{
	vec.x *= mult;
	vec.y *= mult;
	return (vec);
}

t_vec2	t_vec2__addx(t_vec2 vec, double x)
{
	vec.x += x;
	return (vec);
}

t_vec2	t_vec2__addy(t_vec2 vec, double y)
{
	vec.y += y;
	return (vec);
}

t_vec2	t_vec2__normalize(t_vec2 vec)
{
	double	len;

	len = sqrt(pow2(vec.x) + pow2(vec.y));
	if (len == 0)
		return (t_vec2__new(0, 0));
	return (t_vec2__new(vec.x / len, vec.y / len));
}

t_vec2	t_vec2__lerp(t_vec2 origin, t_vec2 target, double progress)
{
	t_vec2	result;

	result.x = lerp(origin.x, target.x, progress);
	result.y = lerp(origin.y, target.y, progress);
	return (result);
}

double	t_vec2__dist(t_vec2 a, t_vec2 b)
{
	double	distance_x;
	double	distance_y;

	distance_x = a.x - b.x;
	distance_y = a.y - b.y;
	return (sqrt(pow2(distance_x) + pow2(distance_y)));
}

t_vec2	t_vec2__follow(t_vec2 current, t_vec2 target, double spacing, double t)
{
	t_vec2  diff;
    t_vec2  ideal_pos;
    double  dist;

    dist = t_vec2__dist(current, target);

    // CAS 1 : On est déjà à la bonne distance (ou plus près)
    if (dist <= spacing)
        return (current);

    // CAS 2 (CRITIQUE) : Protection Division par Zéro
    // Si dist est quasi nul (superposition au spawn), on ne peut pas calculer de direction.
    // On retourne 'current' pour attendre que le parent bouge un peu.
    if (dist < 0.0001) 
        return (current);

    diff.x = current.x - target.x;
    diff.y = current.y - target.y;

    // Calcul normal
    ideal_pos.x = target.x + (diff.x / dist) * spacing;
    ideal_pos.y = target.y + (diff.y / dist) * spacing;

    return (t_vec2__lerp(current, ideal_pos, t));
}