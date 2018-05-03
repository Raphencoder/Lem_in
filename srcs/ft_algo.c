/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:06:46 by alecott           #+#    #+#             */
/*   Updated: 2018/05/03 13:17:25 by alecott          ###   ########.fr       */
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
	if (ants > 0 && (!ft_strequ(info->room_ant[ants - 1], "finished") ||
			!ft_strequ(info->path_ant[ants - 1], info->end)))
		write(1, " ", 1);
	write(1, "L", 1);
	ft_putnbr(ants + 1);
	write(1, "-", 1);
	ft_putstr(info->room_ant[ants]);
	if (ft_nbrooms_in_path(info->path_ant[ants]) > 1)
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
	if (ft_strequ(path, info->end))
		return (1);
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
	int		j;
	int		diff_path;

	i = 0;
	j = 0;
	while (all_paths[i])
	{
		diff_path = ft_nbrooms_in_path(all_paths[i]) -
			ft_nbrooms_in_path(all_paths[0]);
		if (ft_opti_path(info, all_paths[i]) &&
				diff_path <= info->nb_ant - (ants + 1))
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
			if (ft_finished(ants, info))
				over++;
			else if (info->path_ant[ants] != NULL)
				ft_moove(ants, info);
			else
				ft_ant_path(ants, info, all_paths);
			ants++;
		}
		if (over != info->nb_ant)
			ft_putchar('\n');
	}
}
