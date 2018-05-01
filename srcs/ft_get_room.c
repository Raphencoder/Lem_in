/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/30 18:17:27 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char	*ft_get_room(char *room, char *link)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	k = 0;
	i = 0;
	if (room == NULL || link == NULL)
		return (0);
	while (link[i] != '-')
		i++;
	res = ft_strndup(link, i++);
	k = ft_strequ(res, room);
	if (!k)
		return (res);
	ft_strdel(&res);
	j = i;
	while (link[i])
		i++;
	res = (char*)ft_memalloc(sizeof(char) * (i - j + 1));
	i = 0;
	while (link[j])
		res[i++] = link[j++];
	return (res);
}
