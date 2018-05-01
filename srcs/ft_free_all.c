/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/30 18:17:49 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	ft_free_all(char **path, t_ants *info)
{
	int i;

	i = 0;
	while (path[i])
		ft_strdel(&path[i++]);
	free(path);
	i = 0;
	while (info->tmp1[i])
		ft_strdel(&info->tmp1[i++]);
	ft_memdel((void**)info->tmp1);
}
