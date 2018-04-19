/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:14:50 by rkrief            #+#    #+#             */
/*   Updated: 2018/03/05 17:13:24 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static char	*ft_cut(char *s1)
{
	int i;
	char *res;

	i = 0;
	while (s1[i] != '-')
		i++;
	res = (char*)ft_memalloc(sizeof(char) * (i + 2));
	i = 0;
	while (s1[i] != '-')
	{	
		res[i] = s1[i];
		i++;
	}
	return (res);
}

static void	ft_tubret2(char *s1, char *s2, int *i, int *j)
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

static char	*ft_tubret(char *s1, char *s2)
{
	int i;
	int j;

	ft_tubret2(s1, s2, &i, &j);
	if (s1[i] == '-')
		return (ft_strdup(s1 + i + 1));
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
		return (ft_cut(s1));
	return (NULL);
}

static int	ft_chck(char **stock, char *check)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (ft_strequ(stock[i], check))
			return (1);
		i++;
	}
	return (0);
}

static void	ft_fill(char **res, char *look, char **stock, int *j)
{
	int i;
	char *tmp;
	i = 0;
	while (i < ft_tablen(res))
	{
		tmp = ft_tubret(res[i], look);
		if (tmp && !ft_chck(stock, tmp))
		{
			stock[*j] = ft_tubret(res[i], look);
			*j = *j + 1;
		}
		ft_strdel(&tmp);
		i++;
	}
}

int			ft_verify(char *start, char *end, t_ants *info)
{	
	char **stock;
	int i;
	int j;
	int so;

	j = 0;
	i = 1;
	stock = (char**)ft_memalloc(sizeof(char*) * (ft_tablen(info->names) + 1));
	stock[i - 1] = ft_strdup(start);
	while (j < ft_tablen(info->tubes))
	{
		if (!stock[j])
			break ;
		ft_fill(info->tubes, stock[j], stock, &i);
		j++;
	}
	so = ft_chck(stock, end);
	i = 0;
	while (i < ft_tablen(info->names))
		ft_strdel(&stock[i++]);
	free(stock);
	return (so);
}
