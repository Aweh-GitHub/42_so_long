/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:37:11 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/21 13:43:18 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <stdlib.h>
# include <sys/time.h>

#include <stdio.h>

# include "mlx.h"
# include "libft/libft.h"

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_sprite
{
	struct s_asset_img	*idle;
}	t_sprite;

typedef struct s_mlx_behaviour
{
	struct s_entity		*param_ref_entity;
	struct s_game		*param_ref_game;
	int					(*f_update)(struct s_mlx_behaviour *b);
	int					(*f_collision_update)(struct s_mlx_behaviour *b);
}	t_mlx_behaviour;

typedef struct s_entity
{
	struct s_entity			*parent;
	t_list					*childs;
	struct s_sprite			*sprite;
	struct s_mlx_behaviour	*behaviour;
	struct s_vec2			position;
	struct s_vec2			size;
	int						is_spawned;
}	t_entity;

typedef struct s_client_inputs
{
	int				inputs[4];
	struct s_vec2	axis;
}	t_client_inputs;

typedef struct s_img
{
	void	*img_mlx;
	char	*addr;
	int		pixel_size;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_asset_img
{
	struct s_img	*img;
	int				width;
	int				height;
	double			pixel_per_unit;
}	t_asset_img;

typedef struct s_assets
{
	struct s_asset_img	*circle_img;
	struct s_asset_img	*consumbale_apple_img;
}	t_assets;

typedef struct s_game
{
	void					*mlx;
	void					*window;

	struct s_img			frame;

	struct s_client_inputs	*client_inputs;
	struct s_assets			*assets;

	struct timeval			last_timeval;
	struct timeval			last_collision_timeval;
	double					delta_time;

	t_list					*entity_list;
	t_list					*colliders_list;
}	t_game;

# define PLAYER_MOV_SPD 8
# define PLAYER_BODY_MOV_SPD (PLAYER_MOV_SPD * 100)
# define PLAYER_BODY_SPC 0.15

# define WINDOW_W 1280
# define WINDOW_H 720
# define WORLD_PIXELS_PER_UNIT 32
# define TRANSPARENT 0xFF000000

# define INPUT_UP 0
# define INPUT_DOWN	1
# define INPUT_LEFT	2
# define INPUT_RIGHT 3

# define DIRECTION_UP -1
# define DIRECTION_DOWN 1
# define DIRECTION_LEFT -1
# define DIRECTION_RIGHT 1

# define KEY_PRESSED TRUE
# define KEY_RELEASED FALSE

double			timeval_to_sec(struct timeval *tv);

void			init_spawn(t_game *game);
void			spawn_entity(t_game *game, t_entity *entity, t_vec2 position);

int				on_key_press(int keycode, void *uncasted_game);
int				on_key_release(int keycode, void *uncasted_game);

int				render(t_game *game);
void			init_render(t_game *game);
// T_VEC2

t_vec2			t_vec2__new(double x, double y);
t_vec2			t_vec2__add0(t_vec2 vec_src, t_vec2 vec_add);
t_vec2			t_vec2__add1(t_vec2 vec, double x, double y);
t_vec2			t_vec2__add2(t_vec2 vec_src, double add);
t_vec2			t_vec2__sub0(t_vec2 vec_src, t_vec2 vec_sub);
t_vec2			t_vec2__sub1(t_vec2 vec, double x, double y);
t_vec2			t_vec2__sub2(t_vec2 vec, double sub);
t_vec2			t_vec2__mult0(t_vec2 vec_src, t_vec2 vec_add);
t_vec2			t_vec2__mult1(t_vec2 vec_src, double x, double y);
t_vec2			t_vec2__mult2(t_vec2 vec_src, double mult);
t_vec2			t_vec2__addx(t_vec2 vec, double x);
t_vec2			t_vec2__addy(t_vec2 vec, double x);
t_vec2			t_vec2__normalize(t_vec2 vec);
t_vec2			t_vec2__lerp(t_vec2 origin, t_vec2 target, double progress);
double			t_vec2__dist(t_vec2 a, t_vec2 b);
t_vec2			t_vec2__follow(t_vec2 current, t_vec2 target, double spacing, double progress);

// T_SPRITE

t_sprite		*t_sprite__new(t_asset_img *idle);
void			t_sprite__free(t_sprite *sprite);

// T_MLX_BEHAVIOUR

t_mlx_behaviour	*t_mlx_behaviour__new(t_entity *param_ref_entity, t_game *param_ref_game, int (*f_update)(t_mlx_behaviour *), int (*f_collision_update)(t_mlx_behaviour *));
void			t_mlx_behaviour__free(t_mlx_behaviour *behaviour);

//T_ENTITY

t_entity		*t_entity__new(void);
void			t_entity__free(t_entity *entity);
void			t_entity__set_parent(t_entity *child, t_entity *parent);
void			t_entity__add_child(t_entity *entity, t_entity *to_add);

// // T_CLIENT_INPUTS

// int				on_key_press(int keycode, void *uncasted_game);
// int				on_key_release(int keycode, void *uncasted_game);

// T_ASSET_IMG

t_asset_img		*t_asset_img__new(t_game *game, char *path, double ppu);
void			t_asset_img__free(t_asset_img *asset);


// T_ASSETS

t_assets		*t_assets__new();
void			t_assets__add_img(t_assets *assets, void *img);

// T_GAME

t_game			*t_game__new(void *mlx);
void			t_game__free(t_game *game);
void			t_game__add_spawned_entity(t_game *game, t_entity *entity);

// F_BEHAVIOUR_PLAYER

int				f_behaviour_player_update(t_mlx_behaviour *behaviour);

// F_PLAYER_BODYPART

int				f_behaviour_player_bodypart_update(t_mlx_behaviour *behaviour);

// F_BEHAVIOUR_CONSUMABLE

int				f_behaviour_consumable_update(t_mlx_behaviour *behaviour);

// ENTITY_COLLDIER

// int	f_behaviour_collider_collision_update(t_mlx_behaviour *behaviour);


#endif