/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:48:11 by averdon           #+#    #+#             */
/*   Updated: 2022/12/04 22:50:22 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_parsing_map.h"

void	sort_tab(char **tab, int size)
{
	int		count;
	int		count2;
	char	*temp;

	count = 0;
	temp = NULL;
	while (count < size)
	{
		count2 = 1;
		while (count2 < size - 1)
		{
			if (ft_strcmp(tab[count2], tab[count2 + 1]) > 0)
			{
				temp = tab[count2];
				tab[count2] = tab[count2 + 1];
				tab[count2 + 1] = temp;
			}
			count2++;
		}
		count++;
	}
}

char	**complete_tab(char **tab_1, char **tab_new_elements, char **new_tab)
{
	int	i;
	int	j;
	int	num_index_tab_1;
	int	num_index_tab_2;

	i = 0;
	num_index_tab_1 = 0;
	num_index_tab_2 = 0;
	while (tab_1[num_index_tab_1])
		num_index_tab_1++;
	while (tab_new_elements[num_index_tab_2])
		num_index_tab_2++;
	j = 0;
	while (i < num_index_tab_1)
	{
		new_tab[i] = ft_strdup(tab_1[i]);
		i++;
	}
	while (i + j < num_index_tab_1 + num_index_tab_2)
	{
		new_tab[i + j] = ft_strdup(tab_new_elements[j]);
		j++;
	}
	new_tab[i + j] = NULL;
	return (new_tab);
}

void	free_tab(char **tab)
{
	int	i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

char	**ft_join_tab(char **tab_1, char *new_elements, int num_index_tab_1)
{
	int		num_index_tab_2;
	char	**new_tab;
	char	**tab_new_elements;

	tab_new_elements = ft_split(new_elements, ' ');
	if (!tab_new_elements || !tab_new_elements[0])
	{
		free_tab(tab_new_elements);
		return (NULL);
	}
	if (!tab_1)
		return (tab_new_elements);
	num_index_tab_2 = 0;
	while (tab_new_elements[num_index_tab_2])
		num_index_tab_2++;
	new_tab = ft_calloc(num_index_tab_1 + num_index_tab_2 + 1, sizeof(char *));
	if (!new_tab)
		return (NULL);
	new_tab = complete_tab(tab_1, tab_new_elements, new_tab);
	free_tab(tab_new_elements);
	return (new_tab);
}
