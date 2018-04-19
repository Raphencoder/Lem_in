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

static int	ft_search_wrong_tubes(char *str, t_ants *info)
{
	int		i;

	i = 0;
	if (str[0] == '#')
		return (1);
	while (info->names[i])
	{
		if (ft_strequ(str, info->names[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_error3prev(t_ants *info, int *i, int *j, int *k)
{
	*k = 0;
	*j = 0;
	if (info->tubes[*i][0] == '#')
		return (1);
	while (info->tubes[*i][*j] && info->tubes[*i][*j] != '-')
		*j = *j + 1;
	*j = *j + 1;
	while (info->tubes[*i][*j + *k])
		*k = *k + 1;
	return (0);
}

static int	ft_error3(t_ants *info)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	while (info->tubes[i])
	{
		if (ft_error3prev(info, &i, &j, &k))
			return (1);
		str = (char*)malloc(sizeof(char) * (k + 1));
		k = 0;
		while (info->tubes[i][j + k])
		{
			str[k] = info->tubes[i][j + k];
			k++;
		}
		str[k] = '\0';
		if (!ft_search_wrong_tubes(str, info))
			return (0);
		ft_strdel(&str);
		i++;
	}
//	return (1);
	return (ft_verify(info->start, info->end, info));
}

static int	ft_error2(t_ants *info)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (info->tubes[i])
	{
		j = 0;
		while (info->tubes[i][j] && info->tubes[i][j] != '-')
			j++;
		str = (char*)malloc(sizeof(char) * (j + 1));
		j = 0;
		while (info->tubes[i][j] && info->tubes[i][j] != '-')
		{
			str[j] = info->tubes[i][j];
			j++;
		}
		str[j] = '\0';
		if (!ft_search_wrong_tubes(str, info))
			return (0);
		ft_strdel(&str);
		i++;
	}
	return (ft_error3(info));
}

int			ft_error(t_ants *info)
{
	int		i;
	int		n;
	int		j;
	int		k;

	if (!ft_norm(info, &i, &j, &n))
		return (0);
	while (info->names[j])
	{
		k = 0;
		while (info->tubes[k])
		{
			if (ft_tubestr(info->tubes[k], info->names[j]))
			{
				n++;
				break ;
			}
			k++;
		}
		j++;
	}
	if (n != i)
		return (0);
	return (ft_error2(info));
}
