/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:45:09 by averdon           #+#    #+#             */
/*   Updated: 2022/12/04 21:29:13 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_parsing_map.h"

void	add_files_manually(char ***files, int *nb_files)
{
	char	**temp;

	temp = ft_join_tab(*files, "non_existent.ber", *nb_files);
	free_tab(*files);
	*files = temp;
	(*nb_files)++;
}

char	**create_tab_directory(char *path)
{
	DIR				*directory;
	struct dirent	*new_file;
	int				nb_files;
	char			**files;
	char			**temp;

	directory = opendir(path);
	nb_files = 0;
	files = NULL;
	if (directory)
	{
		new_file = readdir(directory);
		while (new_file)
		{
			temp = ft_join_tab(files, new_file->d_name, nb_files);
			free_tab(files);
			files = temp;
			new_file = readdir(directory);
			nb_files++;
		}
		closedir(directory);
		add_files_manually(&files, &nb_files);
		sort_tab(files, nb_files);
	}
	return (files);
}
