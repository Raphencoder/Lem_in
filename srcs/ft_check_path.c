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

int     ft_check_path(char *path, char **allpath)
{
	int i;

	i = 0;
	if (allpath == NULL)
		return (0);
	while (allpath[i])
	{
		if (ft_strequ(path, allpath[i]))
			return (1);
		i++;
	}
	return (0);
}
