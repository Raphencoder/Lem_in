/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 18:24:20 by alecott           #+#    #+#             */
/*   Updated: 2018/04/30 18:30:59 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char	*ft_take_room(char *path)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = 0;
	while (path[i] && path[i] != '-')
	{
		i++;
		len++;
	}
	i = 0;
	ret = (char*)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		ret[i] = path[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
