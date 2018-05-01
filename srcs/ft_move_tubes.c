/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/30 18:18:08 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	ft_move_two(char **tubes)
{
	int		i;
	char	*clone;

	i = 0;
	while (tubes[i] && tubes[i + 1])
	{
		clone = tubes[i + 1];
		tubes[i + 1] = tubes[i];
		tubes[i++] = clone;
	}
}

void	ft_move_triple(char **tubes)
{
	int		i;
	int		j;
	char	*clone;

	i = 0;
	j = 0;
	while (tubes[i] && tubes[i + 2])
	{
		clone = tubes[i];
		tubes[i] = tubes[i + 2];
		tubes[i + 2] = clone;
		i++;
	}
}

void	ft_move_back(char **tubes)
{
	int		i;
	int		j;
	char	*clone;

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

void	ft_move_tubes(char **tubes)
{
	static int l;

	if (l == 0)
		ft_move_back(tubes);
	if (!(l % 5))
		ft_move_back(tubes);
	else if (l % 2)
	{
		ft_move_two(tubes);
		ft_move_triple(tubes);
	}
	else
		ft_move_two(tubes);
	l++;
}
