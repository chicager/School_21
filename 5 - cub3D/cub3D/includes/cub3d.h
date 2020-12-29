/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:27:17 by curreg            #+#    #+#             */
/*   Updated: 2020/10/20 20:55:40 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SCALE 64
# define NO 0
# define SO 1
# define EA 2
# define WE 3
# define S 4

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../gnl/get_next_line.h"
# include "../utils/utils.h"
# include "../minilibx_mms/mlx.h"

typedef struct	s_sprite {
	double		sprite_dir;
	double		sprite_dist;
	double		sprite_screen_size;
	double		h_offset;
	double		v_offset;
	int			i;
	int			j;
	int			count;
	double		step;
	int			color;
}				t_sprite;

typedef struct	s_mapflag
{
	int			floor;
	int			ceil;
	int			res;
	int			tex[5];
}				t_mapflag;

typedef struct	s_printmap
{
	int			i;
	int			j;
	int			m;
	int			y_start;
	int			x_start;
	int			size;
}				t_printmap;

typedef struct	s_print3d
{
	double		len_3d;
	double		start;
	double		end;
	int			count;
	int			color;
	double		ratio;
	double		init_start;
	int			count_y_pixel;
}				t_print3d;

typedef struct	s_sort_spr
{
	int			i;
	int			j;
	int			sprite_dist;
	double		temp_sprites_arr1;
	double		temp_sprites_arr2;
	int			min_position;
	int			tmp;
}				t_sort_spr;

typedef struct	s_fill_sp
{
	int x_start;
	int y_start;
	int i;
	int j;
	int m;
}				t_fill_sp;

typedef struct	s_ray_dist
{
	double		xa;
	double		ya;
	double		px;
	double		py;
	double		ay;
	double		ax;
	double		bx;
	double		by;
	double		len_hor;
	double		len_ver;
	int			i;
	int			j;
	int			i1;
	int			j1;
	int			end_mas_y;
	int			size;
}				t_ray_dist;

typedef struct	s_vars
{
	char		**map_array;
	double		p_x;
	double		p_y;
	double		length_ray;
	double		ray_start;
	double		ray_end;
	double		ray_dir;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*mlx_win;
	void		*img_text;
	char		*paths[5];
	char		*img_text_addr;
	char		*img_text_addr_w;
	char		*img_text_addr_n;
	char		*img_text_addr_s;
	char		*img_text_addr_e;
	char		*img_text_addr_sp;
	int			img_width;
	int			img_height;
	int			textb_per_pixel;
	int			text_line_length;
	int			text_endian;
	double		player_pos;
	double		ray_initial;
	double		text_x;
	int			is_player_set;
	int			player_placed;
	double		mas_ray[3000];
	int			x_res;
	int			y_res;
	int			floor_col;
	int			ceil_col;
	int			sprites_count;
	double		*sprites_arr;
	t_mapflag	mapflag;
	t_printmap	p;
	t_ray_dist	ray;
}				t_vars;

typedef struct	s_check {
	int			pos_x;
	int			pos_y;
	int			pos_x_rs;
	int			pos_y_rs;
	int			pos_x_re;
	int			pos_y_re;
}				t_check;

void			set_window(t_vars *vars);
void			set_game(t_vars *vars, char **argv);
void			print_map(t_vars *vars, int y_start, int x_start, int size);
void			my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void			ft_putstr_fd(char *s, int fd);
char			**list_to_array(int size, t_list **tmp);
void			read_map(char **argv, t_vars *vars);
void			init(t_vars *vars);
double			ray_dist(t_vars *vars, double pow, int scale);
void			set_initial_rays(t_vars *vars, char dir);
void			set_rays(t_vars *vars);
void			print_rays(t_vars *vars);
int				close_on_x();
int				key_press(int keycode, t_vars *vars);
void			print_3d(float len, t_vars *vars, float x, double angle_ray);
void			parse_texture(t_vars *vars);
void			init_sprite_arr(t_vars *vars);
void			print_sprite(double spr_x, double spr_y, t_vars *vars);
void			get_sprites_count(t_vars *vars, int size);
void			fill_sprites_arr(t_vars *vars, int size);
void			take_screenshot(t_vars *vars);
int				check_straight_wall(t_vars *vars);
int				check_left_wall(t_vars *vars);
int				check_right_wall(t_vars *vars);
int				check_back_wall(t_vars *vars);
void			sort_sprites_arr(t_vars *vars);
void			keycode_124(t_vars *vars);
void			keycode_123(t_vars *vars);
void			keycode_13(t_vars *vars);
void			keycode_0(t_vars *vars);
void			keycode_1(t_vars *vars);
void			keycode_2(t_vars *vars);
void			print_frame(t_vars *vars);
void			ray_dist_init(t_vars *vars, int scale);
void			ray_dist_aux(t_vars *vars, double pow);
void			ray_dist_aux2(t_vars *vars, double pow);
void			check_map_array(t_vars *vars);
int				check_map(t_vars *vars, int i, int j);
uint32_t		ft_get_color(char *str);
void			ft_parse_textures(t_vars *vars, char *str);
void			ft_get_resolution(t_vars *vars, char *str);
void			ft_parse_ints(t_vars *vars, char *str);
void			check_player_placed(t_vars *vars);
void			check_int_val(t_vars *vars, char c);
void			put_error(char *str);
void			init_fill_sp(t_fill_sp *fill_sp);
int				get_color(t_vars *vars, int x, int y);
int				get_color_scr(t_vars *vars, int x, int y);

#endif
