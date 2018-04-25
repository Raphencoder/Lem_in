/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:57:17 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/25 17:52:51 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

void	ft_move_two(char **tubes)
{
	int i;
	char *clone;

	i = 0;
	while (tubes[i] && tubes[i + 1])
	{
		clone = tubes[i + 1];
		tubes[i + 1] = tubes[i];
		tubes[i++] = clone;
	}

}

void	ft_move_back(char **tubes)
{
	int i;
	int j;
	char *clone;

	i = 0;
	j = 0;
	while (tubes[i])
		i++;
	i--;
	while (j < i)
	{
		clone = tubes[j];
		tubes[j++] = tubes[i];
		tubes[i--] = clone;
	}

}

int	ft_move_tubes(char **tubes)
{
	static int l;

	if (!(l % 2))
	{
		ft_putendl("hey");
		ft_move_back(tubes);
//		ft_move_two(tubes);
	}
	else
	{
		ft_move_back(tubes);
		ft_move_two(tubes);
	}
	l++;
	return (l);
}

int main()
{
	char *path;
	char *room;
	char *tab[100];
	
	path = ft_strdup("1-2");
	room = ft_strdup("3-2");
	tab[0] = ft_strdup("1-2");
	tab[1] = ft_strdup("3-2");
	tab[2] = ft_strdup("1-3");
	tab[3] = ft_strdup("3-1");
	ft_move_tubes(tab);
	int i;
	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);

	return (0);
}
