/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/30 18:11:49 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char		*ft_complete_path(char *path, char *room, int i, t_ants info)
{
	char	*tmp;
	char	*tmpp;

	tmpp = ft_get_room(room, info.tubes_names[i]);
	tmp = path;
	path = (ft_strjoin(tmp, "-"));
	ft_strdel(&tmp);
	tmp = path;
	path = ft_strjoin(tmp, tmpp);
	ft_strdel(&tmp);
	ft_strdel(&tmpp);
	return (path);
}
