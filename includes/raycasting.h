/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:05:55 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 16:04:34 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "./../minilibx-linux/mlx.h"
# include "cub3d.h"
# include <math.h>

void					update_dir(t_rc *rc);
int						update(t_rc *rc);
void					update_img(t_rc *rc);
unsigned int			start_graphic(t_rc *rc);
void					fill_pixel(char *img, t_pix *pixel, int height,
						int width);
void					draw_ceil_rgb(t_rc *rc, unsigned int *count,
						unsigned int i);
void					draw_floor_rgb(t_rc *rc, unsigned int *count,
						unsigned int i);
void					clear_image(t_rc *rc);
void					draw_map(t_rc *rc);
void					update_map(t_rc *rc);
void					draw_bg(t_rc *rc);
void					draw_player(t_rc *rc);
void					init_sprite_data(int *l, t_sprite *sprite,
						t_rc *rc, int r_nb);
void					update_canvas(unsigned int *i, int *l,
						t_sprite *sprite, t_rc *rc);
t_sprite				*reverse_sprite(t_sprite *b_sprite);
unsigned int			collide_sprite(t_sprite *sprite);
void					draw_sprite(t_rc *rc, int r_nb, t_ray *ray);
void					select_pix_1(int *l, t_sprite *sprite,
						unsigned int *i, t_rc *rc);
void					which_sprite(int *l, t_sprite *sprite,
						unsigned int *i, t_rc *rc);
void					calculate_den(t_ray *ray, t_rc *rc, t_sprite *sprite);
void					line_inter(t_ray *ray, t_rc *rc, t_sprite *sprite);
void					manage_sprite_gap(t_rc *rc, t_sprite *sprite,
						int r_nb);
void					apply_offset_value_sprite(t_rc *rc, int *l,
						t_sprite *sprite);
double					offset_row_sprite(t_rc *rc, t_sprite *sprite);
void					skip_line_sprite(int *l, t_rc *rc, double line_skipped,
						t_sprite *sprite);
void					fill_sprite(t_rc *rc, int *l, unsigned int *i,
						t_sprite *sprite);
void					select_pix_2(int *l, t_sprite *sprite,
						unsigned int *i, t_rc *rc);
double					offset_value_sprite(int offset_row,
						unsigned int size_s,
						t_rc *rc, t_sprite *sprite);
void					apply_offset_value_image(t_rc *rc,
						double offset_value_img, int *l, t_ray *ray);
void					manage_gap(t_rc *rc, int r_nb, unsigned int *size_w);
void					manage_offset(int *l, t_ray *ray, t_rc *rc,
						unsigned int size_w);
void					browse_width_ray(t_rc *rc, int *l, int *i, t_ray *ray);
void					draw_texture(t_rc *rc, int r_nb, unsigned int size_w,
						t_ray *ray);
unsigned int			offset_column(t_ray *ray, t_rc *rc);
double					offset_row_img(t_rc *rc, double offset_value_img,
						double perc_row, t_ray *ray);
void					skip_line(int *l, t_rc *rc, t_ray *ray);
void					fill_texture(t_rc *rc, int l, int i, t_ray *ray);
unsigned int			apply_offset_value_image_no_so(t_ray *ray, t_rc *rc,
						int *l, double offset_value_img);
double					offset_value_image(int offset_row, unsigned int size_w,
						t_rc *rc, t_ray *ray);
unsigned int			apply_perc_col(t_ray *ray, t_rc *rc, double perc_col);

void					free_map(t_rc *rc);
void					free_mem(t_rc *rc);
void					free_path(t_rc *rc);
void					del(void *content);
void					free_sprite(t_rc *rc);

int						keyrelease(int keycode, t_rc *rc);
int						keypressed(int keycode, void *data);

unsigned int			read_text_2(t_rc *rc);
unsigned int			read_sprite(t_rc *rc);
void					init_move(t_rc *rc);
unsigned int			init_frame(t_rc *rc);
unsigned int			init_rc(t_rc *rc);
void					init_rot(t_rc *rc);
t_pix					*init_pixel(int r, int g, int b);
void					init_player(t_rc *rc);
void					init_bg(t_rc *rc);
void					init_m_map(t_rc *rc);
void					init_dir(t_rc *rc);
unsigned int			read_text(t_rc *rc);
void					init_struct(t_rc *rc);
void					init_img_text(t_rc *rc);
void					init_img_sprite(t_rc *rc);
void					turn(t_rc *rc);
void					run(t_rc *rc);
void					move_up_down(t_rc *rc);
void					move_left_right(t_rc *rc);
void					move(t_rc *rc);

void					init_ver(double current_ray_angle, t_rc *rc,
						t_ray *ray);
void					ray_len(t_rc *rc, t_ray *ray,
						double current_ray_angle);
void					ray_vert(t_rc *rc, t_ray *ray,
						double angle_from_player,
						double *w_height);
void					ray_hor(t_rc *rc, t_ray *ray, double angle_from_player,
						double *w_height);
unsigned int			cast_rays(t_rc *rc);
void					first_inter_dir(t_rc *rc, double current_ray_angle);
void					delta_dir(t_rc *rc, double current_ray_angle);
void					sprite_h_data(t_ray *ray, t_sprite *sprite, t_rc *rc);
void					init_hor(double current_ray_angle, t_rc *rc,
						t_ray *ray);
unsigned int			find_coor_inter_hor(t_rc *rc, t_ray *ray,
						double current_ray_angle);
double					adjust_angle(double current_ray_angle);
t_ray					*init_ray(void);
void					first_hor_inter_under_pi(t_rc *rc,
						double current_ray_angle);
void					first_hor_inter(t_rc *rc, double current_ray_angle);
void					first_ver_inter(t_rc *rc, double current_ray_angle);
unsigned int			is_wall(t_rc *rc, int x, int y);
double					from_deg_to_rad(double deg);
unsigned int			save_or_display(t_rc *rc);
unsigned int			init_data_casting(t_rc *rc, t_ray **ray,
						double current_ray_angle);
void					data_rays(t_rc *rc, double current_ray_angle);
void					calculate_offset_w_h(int ray_nb, t_rc *rc, t_ray *ray);
void					calculate_offset_w_v(int ray_nb, t_rc *rc, t_ray *ray);
void					delta_hor(t_rc *rc, double current_ray_angle);
void					delta_ver(t_rc *rc, double current_ray_angle);
double					line_length(double x1, double y1, double x2,
						double y2);

void					save_img(t_rc *rc);
unsigned int			bitmap_info_header(int fd, t_rc *rc);
void					fill_pixels_save(int *j, unsigned int *l,
						char *pixels, t_rc *rc);
void					fill_offset(unsigned int *l, char *pixels,
						unsigned int offset);
unsigned int			color_table(int fd, t_rc *rc);
unsigned int			save(t_rc *rc);
char					*ini_nb(int size_nb, char *nb_hexa);
void					fill_nb(int size_nb, char *nb, char *nb_hexa);
unsigned int			add_to_file(char *nb_hexa, int fd, int size_nb);
unsigned int			add_nb_to_file(unsigned long long int nb, int fd,
						unsigned int nb_byte);
unsigned int			bitmap_file_header(int fd, t_rc *rc);
unsigned int			hexa_size(unsigned long long int nb);
void					stock_hexa(unsigned long long int nb, char *nb_hexa,
						char *hexa, int i);
int						eq_hexa(char *hexa, char c);
int						atoi_hexa(char *nb_hexa);
unsigned int			add_closest(t_rc *rc, t_sprite **h_sprite,
						t_sprite **v_sprite);
unsigned int			add_closest_vert(t_rc *rc, t_sprite **v_sprite);
unsigned int			add_closest_hor(t_rc *rc, t_sprite **h_sprite);
unsigned int			join_sprite(t_rc *rc);
t_sprite				*dup_sprite(t_sprite *sprite);
unsigned int			insert_sprite_ver(t_sprite *sprite, int sprite_id,
						t_rc *rc, t_ray *ray);
unsigned int			find_coor_inter_ver(t_rc *rc, t_ray *ray,
						double current_ray_angle);
void					draw_ray(t_rc *rc, t_ray *ray, int ray_nb);
double					init_casting(t_rc *rc, double *gap);
void					lst_clear(t_sprite **sprite, void (*del)(void *));
unsigned int			is_sprite(t_rc *rc, int x, int y);
t_sprite				*last_sprite(t_sprite *lst);
void					add_sprite(t_sprite **alst, t_sprite *new);
t_sprite				*new_sprite(void);
void					sprite_v_data(t_ray *ray, t_sprite *sprite, t_rc *rc);
int						redcross(void *data);
void					check_resolution(t_rc *rc);
void					put_rc_error(unsigned int error);
int						detect_file_error(int argc, char **argv);

void					put_file_error(unsigned int error);
unsigned int			check_file_ext(char *file_name);
#endif
