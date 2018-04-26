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

void	ft_feel_free(t_ants *info, char **clonepath)
{
	int l;

	ft_strdel(&info->room);
	ft_strdel(&info->rm);
	ft_strdel(&info->path);
	l = 0;
	while (clonepath[l])
		ft_strdel(&(clonepath[l++]));
	ft_memdel((void**)clonepath);
	free(clonepath);
}
