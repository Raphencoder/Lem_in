/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:57:46 by alecott           #+#    #+#             */
/*   Updated: 2018/04/20 12:57:57 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	ft_print(t_ants *info)
{
	int		i;

	ft_putstr("info.nb_ant = ");
	ft_putnbr(info->nb_ant);
	write(1, "\n", 1);
	i = 0;
	ft_putendl("info.rooms = ");
	while (info->rooms[i])
	{
		ft_putendl(info->rooms[i]);
		i++;
	}
	i = 0;
	ft_putendl("info.names = ");
	while (info->names[i])
	{
		ft_putendl(info->names[i]);
		i++;
	}
	i = 0;
	ft_putendl("info.tubes = ");
	while (info->tubes[i])
	{
		ft_putendl(info->tubes[i]);
		i++;
	}
	ft_putstr("info.start= ");
	ft_putendl(info->start);
	ft_putstr("info.end= ");
	ft_putendl(info->end);
}

int			main(void)
{
	t_ants	info;

	ft_bzero(&info, sizeof(t_ants));
	if (!ft_stock(&info))
	{
		ft_putstr("ERROR1");
		return (0);
	}
	ft_names(&info);
	if (!ft_error(&info))
	{
		ft_putstr("ERROR2");
		return (0);
	}
	ft_print(&info);
	ft_fill_path(info);
	while (1);
	return (0);
}