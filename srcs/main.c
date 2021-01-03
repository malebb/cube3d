/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:16:55 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 17:41:06 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"
#include "parse.h"
#include "main.h"

unsigned int	check_file_ext(char *file_name)
{
	unsigned int	size_name;

	size_name = ft_strlen(file_name);
	if (size_name < 4)
		return (FALSE);
	if (ft_strncmp(&file_name[size_name - 4], ".cub", 4) != 0)
		return (FALSE);
	return (TRUE);
}

void			put_file_error(unsigned int error)
{
	if (error == ER_FILENAME)
		ft_putstr("Error\nWrong file extension: only .cub\n");
	else if (error == ER_NOFILE)
		ft_putstr("Error\nNo .cub file specified\n");
	else if (error == ER_UNKNOWN_CUB)
		ft_putstr("Error\n.cub file specified doesn't exist\n");
	else if (error == ER_SAVE)
		ft_putstr("Error\nSecond argument should be --save if specified\n");
}

unsigned int	check_save(char *third_arg, t_rc *rc)
{
	if (!ft_strncmp(third_arg, "--save", 6))
	{
		rc->save = 1;
		return (TRUE);
	}
	return (FALSE);
}

int				check_file(int argc, char **argv, t_rc *rc)
{
	int			fd;

	if (detect_file_error(argc, argv) != 1)
		return (ER_FILE);
	if (argc == 3)
	{
		if (!check_save(argv[2], rc))
		{
			put_file_error(ER_SAVE);
			return (ER_FILE);
		}
	}
	else
		rc->save = FALSE;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		put_file_error(ER_UNKNOWN_CUB);
		return (ER_FILE);
	}
	return (fd);
}

int				main(int argc, char **argv)
{
	int			fd;
	t_rc		*rc;

	rc = ini_parse();
	if ((fd = check_file(argc, argv, rc)) == -1)
	{
		free(rc->p);
		free(rc);
		return (ERROR);
	}
	if (!(rc = parse(&rc, fd)))
		return (ERROR);
	if (!start_graphic(rc))
		ft_putstr("Error\nCheck your path names\n");
	return (0);
}
