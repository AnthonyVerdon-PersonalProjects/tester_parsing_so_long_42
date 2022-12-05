/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:50:04 by averdon           #+#    #+#             */
/*   Updated: 2022/12/05 18:11:47 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_parsing_map.h"

int	no_output(void)
{
	ft_fdprintf(1, RED BOLD"[Program crashed or started] "NC);
	return (1);
}

void	analyse_output(char **str, int fd, int *error_detected)
{
	if (ft_strnstr(*str, "Error\n", ft_strlen(*str)) == 0)
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
	else if (*error_detected != 1)
		ft_fdprintf(1, GREEN BOLD"[OK] "NC);
	free(*str);
	*str = get_next_line_bonus(fd);
}

int	check_output_user(char *file, int fd)
{
	char	*str;
	int		error_detected;

	skip_trace(fd);
	ft_fdprintf(1, BOLD"%s : "NC, file);
	str = get_next_line_bonus(fd);
	error_detected = 0;
	if (!str)
	{
		error_detected = 1;
		no_output();
	}
	else
		analyse_output(&str, fd, &error_detected);
	return (error_detected);
}
