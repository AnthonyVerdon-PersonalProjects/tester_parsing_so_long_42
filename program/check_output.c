/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:50:04 by averdon           #+#    #+#             */
/*   Updated: 2022/12/04 20:45:49 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_parsing_map.h"

int	no_output(int signal)
{
	if (signal)
		ft_fdprintf(1, RED BOLD"[Program crashed] "NC);
	else
		ft_fdprintf(1, RED BOLD"[Program shouldn't start] "NC);
	return (1);
}

void	analyse_output(char **str, int fd, int *error_detected)
{
	if (ft_strncmp(*str, "Error\n", 6) != 0)
	{
		ft_fdprintf(1, RED BOLD"[No error message] "NC);
		*error_detected = 1;
	}
	free(*str);
	*str = get_next_line_bonus(fd);
	if (!(*str))
	{
		ft_fdprintf(1, RED BOLD"[No explication of the error] "NC);
		*error_detected = 1;
	}
	else if (ft_strncmp(*str, "Error\n", 6) != 0)
	{
		ft_fdprintf(1, GREEN BOLD"[OK] "NC);
		*error_detected = 0;
	}
	free(*str);
	*str = get_next_line_bonus(fd);
}

int	check_output_user(char *file, int fd, int signal)
{
	char	*str;
	int		error_detected;

	skip_trace(fd);
	ft_fdprintf(1, BOLD"%s : "NC, file);
	str = get_next_line_bonus(fd);
	if (!str)
	{
		error_detected = 1;
		no_output(signal);
	}
	else
		analyse_output(&str, fd, &error_detected);
	return (error_detected);
}
