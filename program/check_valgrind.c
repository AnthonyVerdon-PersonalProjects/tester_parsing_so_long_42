/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valgrind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:50:16 by averdon           #+#    #+#             */
/*   Updated: 2022/12/04 20:45:46 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_parsing_map.h"

void	message_valgrind(int memory)
{
	if (memory)
		ft_fdprintf(1, RED BOLD"[Valgrind Error]\n"NC);
	else
		ft_fdprintf(1, GREEN BOLD"[Valgrind OK]\n"NC);
}

int	check_valgrind_user(int mode, int *signal)
{
	char	*str;
	int		fd;
	int		memory;
	char	*error_signal_message;

	fd = open("valgrind_output.txt", O_RDONLY);
	str = get_next_line_bonus(fd);
	memory = 0;
	error_signal_message = "Process terminating with default action of signal";
	while (str)
	{
		if (ft_strnstr(str, "LEAK SUMMARY", ft_strlen(str)) != 0)
			memory = 1;
		else if (ft_strnstr(str, "errors in context", ft_strlen(str)) != 0)
			memory = 1;
		else if (ft_strnstr(str, error_signal_message, ft_strlen(str)) != 0)
			*signal = 1;
		free(str);
		str = get_next_line_bonus(fd);
	}
	if (mode)
		message_valgrind(memory);
	close(fd);
	return (memory);
}
