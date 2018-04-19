/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_names.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:13:15 by alecott           #+#    #+#             */
/*   Updated: 2018/04/10 10:33:51 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	ft_nbrooms(t_ants *info)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (info->rooms[i])
	{
		if (info->rooms[i][0] != '#')
			len++;
		i++;
	}
	return (len);
}

static void	ft_end(t_ants *info)
{
	int		i;
	int		j;
	size_t	len;

	len = 0;
	i = 0;
	j = 0;
	while (info->rooms[i])
	{
		if (ft_strequ(info->rooms[i], "##end"))
		{
			while (info->rooms[i + 1][len] != ' ')
				len++;
			while (info->names[j])
			{
				if (ft_strnequ(info->names[j], info->rooms[i + 1], len))
					info->end = info->names[j];
				j++;
			}
		}
		i++;
	}
}

static void	ft_start(t_ants *info)
{
	int		i;
	int		j;
	size_t	len;

	len = 0;
	i = 0;
	j = 0;
	while (info->rooms[i])
	{
		if (ft_strequ(info->rooms[i], "##start"))
		{
			while (info->rooms[i + 1][len] != ' ')
				len++;
			while (info->names[j])
			{
				if (ft_strnequ(info->names[j], info->rooms[i + 1], len) && 
					info->rooms[i + 1][len] == ' ')
					info->start = info->names[j];
				j++;
			}
		}
		i++;
	}
	ft_end(info);
}

void		ft_names(t_ants *info)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	j = 0;
	len = ft_nbrooms(info);
	info->names = (char**)ft_memalloc(sizeof(char*) * (len + 1));
	while (info->rooms[i])
	{
		len = 0;
		if (info->rooms[i][0] != '#')
		{
			while (info->rooms[i][len] != ' ')
				len++;
			info->names[j] = ft_strsubinv(info->rooms[i], len);
			j++;
		}
		i++;
	}
	info->names[j] = NULL;
	ft_start(info);
}
