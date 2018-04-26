/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/26 12:59:20 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	ft_choose_nbofrm(int *clonem, t_ants *info)
{
	info->m++;
	*clonem = info->m;
	while ((size_t)info->m > (ft_strlen(info->path) / 2))
		info->m--;
	while(info->m)
	{
		if (info->rm)
			ft_strdel(&info->rm);
		info->rm = ft_rm_last_one(info->path);
		info->m--;
	}
	info->m = *clonem;
	ft_strdel(&info->room);
	info->room = ft_get_last_inpath(info->path);

}
