/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:57:46 by alecott           #+#    #+#             */
/*   Updated: 2018/04/27 09:33:08 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	ft_print(t_ants *info)
{
	int		i;

	ft_putnbr(info->nb_ant);
	write(1, "\n", 1);
	i = 0;
	while (info->rooms[i])
	{
		ft_putendl(info->rooms[i]);
		i++;
	}
	i = 0;
	while (info->tubes[i])
	{
		ft_putendl(info->tubes[i]);
		i++;
	}
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
	ft_tubes_names(&info);
	if (!ft_error(&info))
	{
		ft_putstr("ERROR2");
		return (0);
	}
	ft_print(&info);
	ft_fill_path(&info);
	while (1);
	return (0);
}
