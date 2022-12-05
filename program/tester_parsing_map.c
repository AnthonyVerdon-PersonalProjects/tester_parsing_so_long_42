/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_parsing_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:26:16 by averdon           #+#    #+#             */
/*   Updated: 2022/12/04 21:51:46 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_parsing_map.h"

void	check_file_existence(void)
{
	int	value;

	value = access("../so_long", F_OK);
	if (value)
	{
		ft_fdprintf(1, RED BOLD"Executable doesn't exist !"NC);
		exit (0);
	}
}

int	main(void)
{
	char	**files;
	char	**args;
	int		fd_read;
	int		fd_write;
	int		error_detected;

	check_file_existence();
	remove("stdout.txt");
	fd_write = open("stdout.txt", O_CREAT | O_WRONLY | O_TRUNC, 777);
	fd_read = open("stdout.txt", O_RDONLY);
	files = create_tab_directory("wrong_map");
	init_valgrind_arg(&args);
	error_detected = launch_map_test(files, args, fd_read, fd_write);
	free_tab(files);
	free(args);
	close(fd_read);
	close(fd_write);
	if (error_detected)
		ft_fdprintf(1, RED BOLD"\nCheck output files for errors !"NC);
	else
		ft_fdprintf(1, GREEN BOLD"\nWell Done !"NC);
	return (0);
}
