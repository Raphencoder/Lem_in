/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/03 14:13:08 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	ft_nextoffind(t_ants *info, char **path)
{
	int	i;

	i = 0;
	ft_strdel(&info->tmp);
	info->tmp1 = path;
	ft_ultim_path(info, path);
	info->tmpp = info->ultim_path;
	info->ultim_path = ft_sort_paths(info->tmpp);
	info->room_ant = (char**)ft_memalloc(sizeof(char*) * (info->nb_ant + 1));
	info->path_ant = (char**)ft_memalloc(sizeof(char*) * (info->nb_ant + 1));
	ft_algo(info, info->ultim_path);
	while (info->tmpp[i])
		ft_strdel(&info->tmpp[i++]);
	ft_memdel((void**)info->tmpp);
}
