/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tubestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:14:50 by rkrief            #+#    #+#             */
/*   Updated: 2018/03/02 11:35:13 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	ft_tubestr2(char *s1, char *s2, int *i, int *j)
{
	*i = 0;
	*j = 0;
	while (s1[*i] != '-')
	{
		if (s1[*i] != s2[*i])
			break ;
		*i = *i + 1;
	}
}

int			ft_tubestr(char *s1, char *s2)
{
	int i;
	int j;

	ft_tubestr2(s1, s2, &i, &j);
	if (s1[i] == '-')
		return (1);
	while (s1[i] != '-')
		i++;
	i++;
	while (s1[i])
	{
		if (s1[i] != s2[j])
			break ;
		i++;
		j++;
	}
	if (!s1[i])
		return (1);
	return (0);
}
