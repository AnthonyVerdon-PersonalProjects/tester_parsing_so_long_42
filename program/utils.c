/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:51:42 by averdon           #+#    #+#             */
/*   Updated: 2022/12/04 21:35:42 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_parsing_map.h"

void	init_valgrind_arg(char ***args)
{
	*args = ft_calloc(9, sizeof(char *));
	(*args)[0] = "valgrind";
	(*args)[1] = "--leak-check=full";
	(*args)[2] = "--show-leak-kinds=all";
	(*args)[3] = "-s";
	(*args)[4] = "--log-file=valgrind_output.txt";
	(*args)[5] = "../so_long";
	(*args)[7] = NULL;
}

void	skip_trace(int fd)
{
	char	*str;
	int		i;

	i = 0;
	while (i < 4)
	{
		str = get_next_line_bonus(fd);
		free(str);
		i++;
	}
}

char	*create_trace(char *file, int fd_write)
{
	char	*str;
	char	*temp;

	temp = ft_strjoin(file, "\nYour output:\n");
	str = ft_strjoin("\nTest file:\n", temp);
	free(temp);
	write(fd_write, str, ft_strlen(str));
	free(str);
	return (str);
}
