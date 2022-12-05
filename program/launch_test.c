/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:51:57 by averdon           #+#    #+#             */
/*   Updated: 2022/12/04 22:48:27 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_parsing_map.h"

int	launch_game(char *files, char **args, int fd_read, int fd_write)
{
	int		pid;
	int		error_detected;
	int		signal;

	error_detected = 0;
	args[6] = ft_strjoin("wrong_map/", files);
	create_trace(files, fd_write);
	pid = fork();
	if (pid == 0)
	{
		close(1);
		dup(fd_write);
		execve("/usr/bin/valgrind", args, NULL);
	}
	else
	{
		wait(NULL);
		free(args[6]);
		signal = 0;
		error_detected += check_valgrind_user(0, &signal);
		error_detected += check_output_user(files, fd_read, signal);
		error_detected += check_valgrind_user(1, &signal);
	}
	return (error_detected);
}

int	launch_map_test(char **files, char **args, int fd_read, int fd_write)
{
	int		i;
	int		error_detected;

	i = 2;
	error_detected = 0;
	while (files[i])
	{
		error_detected += launch_game(files[i], args, fd_read, fd_write);
		i++;
	}
	return (error_detected);
}
