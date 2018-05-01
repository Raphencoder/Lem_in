/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:06:46 by alecott           #+#    #+#             */
/*   Updated: 2018/05/01 13:32:39 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	ft_finished(int ants, t_ants *info)
{
	if (ft_strequ(info->room_ant[ants], info->end))
	{
		ft_strdel(&info->room_ant[ants]);
		info->room_ant[ants] = "finished";
		return (1);
	}
	return (0);
}

static void	ft_moove(int ants, t_ants *info)
{
	char	*tmp;
	char	*tmp2;

	if (ft_strequ(info->room_ant[ants], "finished"))
		return ;
	tmp = ft_take_room(info->path_ant[ants]);
	ft_strdel(&info->room_ant[ants]);
	info->room_ant[ants] = tmp;
	write(1, "L", 1);
	ft_putnbr(ants + 1);
	write(1, "-", 1);
	ft_putstr(info->room_ant[ants]);
	write(1, " ", 1);
	if (ft_nbrooms_in_path(info->path_ant[ants]) <= 1)
	{
		ft_strdel(&info->path_ant[ants]);
		info->path_ant[ants] = "finished";
	}
	else
	{
		tmp2 = ft_sub_path(info->path_ant[ants]);
		ft_strdel(&info->path_ant[ants]);
		info->path_ant[ants] = tmp2;
	}
}

static int	ft_opti_path(t_ants *info, char *path)
{
	int		i;

	i = 0;
	while (info->path_ant[i])
	{
		if (info->path_ant[i] != NULL)
		{
			if (ft_strequ(info->path_ant[i], path))
				return (0);
		}
		i++;
	}
	return (1);
}

static void	ft_ant_path(int ants, t_ants *info, char **all_paths)
{
	int		i;

	i = 0;
	while (all_paths[i])
	{
		if (ft_opti_path(info, all_paths[i]))
		{
			info->path_ant[ants] = ft_strdup(all_paths[i]);
			return ;
		}
		i++;
	}
}

void		ft_algo(t_ants *info, char **all_paths)
{
	int		ants;
	int		over;

	over = 0;
	while (over != info->nb_ant)
	{
		ants = 0;
		while (ants < info->nb_ant)
		{
			if (info->path_ant[ants] != NULL)
				ft_moove(ants, info);
			else
				ft_ant_path(ants, info, all_paths);
			if (ft_finished(ants, info))
				over++;
			ants++;
		}
		ft_putchar('\n');
	}
}
