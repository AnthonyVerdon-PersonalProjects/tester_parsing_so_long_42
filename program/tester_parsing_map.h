/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_parsing_map.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:21:20 by averdon           #+#    #+#             */
/*   Updated: 2022/12/04 21:38:11 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_PARSING_MAP_H

# define TESTER_PARSING_MAP_H

# include"libft/libft.h"
# include<dirent.h>
# include<sys/wait.h>
# include<fcntl.h>
# include <stdio.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define NC "\033[0m"
# define BOLD "\e[1m"

int		launch_map_test(char **files, char **args, int fd_read, int fd_write);
int		check_output_user(char *file, int fd, int signal);
int		check_valgrind_user(int mode, int *signal);

char	**create_tab_directory(char *path);
void	free_tab(char **tab);
void	sort_tab(char **tab, int size);
char	**ft_join_tab(char **tab_1, char *new_elements, int num_index_tab_1);

char	*create_trace(char *file, int fd_write);
void	skip_trace(int fd);
void	init_valgrind_arg(char ***args);

#endif
