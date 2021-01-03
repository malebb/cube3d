/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:22:02 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 20:51:25 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../getnextline/get_next_line.h"
# define TRUE			1
# define FALSE			0
# define ERROR			0
# define GOOD			1
# define PI				M_PI
# define UP				119
# define DOWN			115
# define RIGHT			100
# define LEFT			97
# define L_ARROW		65361
# define U_ARROW		65362
# define R_ARROW		65363
# define D_ARROW		65364
# define R_KEY			114
# define ESC			65307
# define SHIFT			65505
# define SIZE_SQUARE	10
# define WIDTH_RAY		1
# define ER_FILE			-1
# define ER_NOFILE			2
# define ER_FILENAME		3
# define ER_UNKNOWN_CUB		4
# define ER_SAVE		20
# define ER_RC			21

typedef struct					s_pix
{
	int							r;
	int							g;
	int							b;
}								t_pix;

typedef struct					s_parsed
{
	unsigned int				rx;
	unsigned int				ry;

	unsigned int				no;
	unsigned int				so;
	unsigned int				we;
	unsigned int				ea;

	unsigned int				s;
	unsigned int				s2;

	unsigned int				f;

	unsigned int				c;

	unsigned int				p;

}								t_parsed;

typedef struct					s_sprite
{
	int							x_mid;
	int							y_mid;
	double						len_main;
	double						len_inter;
	double						angle_to_rot;
	double						r_len;
	double						x1_circle;
	double						y1_circle;
	double						x2_circle;
	double						y2_circle;
	unsigned int				id;
	double						den;
	double						u;
	double						t;
	double						inter_x;
	double						inter_y;
	unsigned int				size_s;
	struct s_sprite				*next;
}								t_sprite;

typedef struct					s_sprite_text
{
	int							w_s1;
	int							h_s1;
	void						*s1;
	char						*s1_data;

	int							w_s2;
	int							h_s2;
	void						*s2;
	char						*s2_data;
}								t_sprite_text;

typedef struct					s_p
{
	unsigned long long int		rx;
	unsigned long long int		ry;

	char						*no;
	char						*so;
	char						*we;
	char						*ea;

	char						*s;
	char						*s2;

	unsigned int				rf;
	unsigned int				gf;
	unsigned int				bf;

	unsigned int				rc;
	unsigned int				gc;
	unsigned int				bc;

	unsigned int				px;
	unsigned int				py;

	char						p;
	char						**map;

	unsigned int				height;
	unsigned int				width;
	unsigned int				fd;
	unsigned int				is_p;
	unsigned int				h_map;
}								t_p;

typedef struct					s_player
{
	double						posx;
	double						posy;
	int							go;
	int							turn;
	int							turn_l;
	int							turn_r;
	double						vel;
	double						rot;
	double						rot_s;
	double						step;
	int							look;
	double						fov;
	unsigned int				run;
}								t_player;

typedef struct					s_text
{
	char						*text_no_data;
	void						*text_no;
	int							w_no;
	int							h_no;
	char						*text_so_data;
	void						*text_so;
	int							w_so;
	int							h_so;
	char						*text_we_data;
	void						*text_we;
	int							w_we;
	int							h_we;
	char						*text_ea_data;
	void						*text_ea;
	int							w_ea;
	int							h_ea;
}								t_text;

typedef struct					s_frame
{
	double						firstx_h;
	double						firsty_h;
	double						firstx_v;
	double						firsty_v;

	double						deltax_h;
	double						deltay_h;
	double						deltax_v;
	double						deltay_v;
	void						*rect;
	char						*rays;
	int							bpp_rays;
	double						plane_dist;
	int							nb_ray;
	double						offset_w;
	int							gap_img;
	double						offset_row;
	unsigned int				left_gap;
	unsigned int				right_gap;
	double						perc_row;
	double						line_skipped;
	double						gap;

	unsigned int				no_dir;
	unsigned int				so_dir;
	unsigned int				ne_dir;
	unsigned int				se_dir;
	t_sprite					*b_h_sprite;
	t_sprite					*b_v_sprite;
	t_sprite					*b_sprite;
	double						offset_value_sprite;
	double						offset_value_img;
}								t_frame;

typedef struct					s_rc
{
	t_p							*p;
	void						*mlx;
	void						*win;
	void						*p_map;
	void						*m_map;
	void						*m_bg;

	t_player					*player;
	t_frame						*frame;

	t_text						*text;
	t_sprite_text				*sprite_text;

	unsigned int				save;
	unsigned int				esc;
	unsigned int				map;
}								t_rc;

typedef struct					s_ray
{
	double						angle;
	int							side;
	double						x_hor;
	double						y_hor;
	double						x_ver;
	double						y_ver;

	double						v_len;
	double						h_len;

	double						r_len;
	double						x_ray;
	double						y_ray;
}								t_ray;

void							free_map(t_rc *rc);
void							free_path(t_rc *rc);
#endif
