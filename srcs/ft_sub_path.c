/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:33:13 by alecott           #+#    #+#             */
/*   Updated: 2018/04/30 16:02:56 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char	*ft_sub_path(char *path)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(path);
	while (path[i] && path[i] != '-')
		i++;
	return (ft_strsub(path, i + 1, len - (i + 1)));
}
