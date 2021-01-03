/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:08:10 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/01 14:01:44 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int		ft_strlength(char *str);
void	ft_strncat(char *dest, char *src, int n);
void	ft_strcpy_from(char *dest, char *src, int j);
int		ft_update_line(char **line, int j, char *buffer);
int		ft_read_file(int fd, char *buffer, char *buf_remains, char **line);
int		ft_finish_buffer(char *buffer, char *buf_remains, char **line);
int		get_next_line(int fd, char **line);
void	ft_empty_buffer(char *buf_remains);
char	*ft_strdup(const char *s1);

#endif
