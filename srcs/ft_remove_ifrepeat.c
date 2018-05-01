/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/01 10:37:28 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char	*ft_remove_ifrepeat(char *rm, int *m, char *path, char *room)
{
	int	clonem;

	*m = *m + 1;
	clonem = *m;
	while ((size_t)*m > (ft_strlen(path) / 2))
		*m = *m - 1;
	while (*m)
	{
		rm = ft_rm_last_one(path);
		*m = *m - 1;
	}
	*m = clonem;
	room = ft_get_last_inpath(path);
	return (room);
}
