/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:50:21 by alecott           #+#    #+#             */
/*   Updated: 2018/03/02 14:03:36 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	ft_sort_tubes_and_repeat(t_ants *info, int *i)
{
	ft_move_tubes(info->tubes_names);
	info->k = info->nb_tubes * 10;
	info->nb_tubes--;
	ft_strdel(&info->rm);
	ft_strdel(&info->room);
	info->room = ft_strdup(info->start);
	if (info->path)
		ft_strdel(&info->path);
	info->path = ft_strdup(info->start);
	info->m = 0;
	*i = 0;
}
