/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:34:52 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/28 13:37:30 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int	ft_norm(t_ants *info, int *i, int *j, int *n)
{
	*i = ft_tablen(info->names);
	*j = 0;
	*n = 0;
	if (info->nb_ant < 0)
		return (0);
	if (info->start == NULL || info->end == NULL)
		return (0);
	return (1);
}
