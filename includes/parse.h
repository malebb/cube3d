/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 05:56:18 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 20:42:37 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# define ER_PLAYER						-1
# define ER_PATH						2
# define ER_RGB							3
# define ER_MAP							4
# define ER_FORMAT						6
# define ER_RESOLUTION					7
# define ER_NO_MAP						8
# include "cub3d.h"

unsigned int			is_parsed(t_parsed *parsed);
unsigned int			assign_and_free_resolution(char *rx, char *ry,
						t_rc *rc);
unsigned int			init_resolution_reading(char *line, unsigned int *i);
unsigned int			check_nb_resolution(char *line, unsigned int i,
						char *rx);
unsigned int			manage_map(int fd, t_rc *rc, char *line);
unsigned int			update_width(unsigned int *current_width, char *line,
						t_rc *rc, int *i);
unsigned int			manage_first_map_line(t_rc *rc, char *line, int *i);
unsigned int			fill_line(t_rc *rc, int *i, char *line);
void					ini_parse_2(t_rc *rc);
unsigned int			read_sprite_path(char *elem, t_parsed *parsed,
						char *line, t_rc *rc);
unsigned int			check_line(char **line, t_parsed *parsed, int status);
t_parsed				*ini_parsed(void);
t_rc					*ini_parse(void);
char					*is_cardinal_point(unsigned int i, char *line);
char					*is_other_elem(unsigned int i, char *line);
char					*which_elem(char *line, t_parsed *parsed);
unsigned int			path_len(char *line, int i);
void					strcpy_n_from(char **dest, char *src, unsigned int n,
						unsigned int from);
unsigned int			allocate_and_fill(char **path, unsigned int size_path,
						char *line, unsigned int i);
unsigned int			skip_start(char *line, unsigned int *i);
unsigned int			read_path(char *line, t_rc *p, char *elem);
unsigned int			read_cardinal_point(t_parsed *parsed, t_rc *p,
						char *elem, char *line);
unsigned int			nb_len(char *line, unsigned int i);
char					*read_rx(char *line, unsigned int i,
						unsigned int *size_nb);
char					*read_ry(char *line, unsigned int i);
unsigned int			read_resolution(char *line, t_rc *p);
void					fill_rgb_elem(t_rc *p, char *elem, unsigned int j,
						unsigned int value);
char					*read_color(char *line, unsigned int *size_nb,
						unsigned int i);
unsigned int			read_rgb(char *line, t_rc *p, char *elem);
unsigned int			read_other_elem(t_parsed *parsed, t_rc *p,
						char *elem, char *line);
unsigned int			read_elem(char *elem, char *line,
						t_parsed *parsed, t_rc *p);
unsigned int			is_line_empty(char *line);
unsigned int			allocate_map(t_rc *p, int height);
void					fill_with_space(unsigned int i,
						unsigned int j, t_rc *p);
void					assign_player(t_rc *p, char *line,
						unsigned int i, unsigned int j);
unsigned int			push_line(t_rc *p, int i, char *line);
void					put_error(int error);
unsigned int			is_elem_here(char *line);
char					*is_elem_sprite(unsigned int i, char *line);
unsigned int			parse_elem(t_parsed *parsed, int fd, t_rc *p);
t_rc					*parse(t_rc **p, int fd);
unsigned int			is_map_valid(char **map, t_rc *p,
						unsigned int i, unsigned int j);
unsigned int			parse_map(int fd, t_rc *p, char *line);
unsigned int			init_stockage(t_rc *p, int *i);
int						stock_map(t_rc *p, char *line, int *i);
unsigned int			is_elem_parsed(char *elem, t_parsed *parsed);
void					display_map(char **map);
char					*check_elem(char *elem, t_parsed *parsed);
unsigned int			check_rgb_end(char *line, unsigned int i);
#endif
