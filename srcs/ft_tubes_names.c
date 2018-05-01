/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tubes_names.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:07:54 by alecott           #+#    #+#             */
/*   Updated: 2018/05/01 10:45:01 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int		ft_nbtubes(t_ants *info)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (info->tubes[i])
	{
		if (info->tubes[i][0] != '#')
			len++;
		i++;
	}
	return (len);
}

void			ft_tubes_names(t_ants *info)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_nbtubes(info);
	info->tubes_names = (char**)ft_memalloc(sizeof(char*) * (len + 1));
	while (info->tubes[i])
	{
		if (info->tubes[i][0] != '#')
		{
			info->tubes_names[j] = info->tubes[i];
			j++;
		}
		i++;
	}
	info->tubes_names[j] = NULL;
}
