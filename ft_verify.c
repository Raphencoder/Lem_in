/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:14:50 by rkrief            #+#    #+#             */
/*   Updated: 2018/03/01 11:31:32 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char		*ft_cut(char *s1)
{
	int i;
	char *res;

	i = 0;
	while (s1[i] != '-')
		i++;
	res = (char*)ft_memalloc(sizeof(char) * (i));
	i = 0;
	while (s1[i] != '-')
	{	
		res[i] = s1[i];
		i++;
	}
	return (res);
}

static void     ft_tubestr2(char *s1, char *s2, int *i, int *j)
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

char		*ft_tubestr(char *s1, char *s2)
{
	int i;
	int j;

	ft_tubestr2(s1, s2, &i, &j);
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

int	ft_nbtubes(char **res)
{
	int i;

	i = 0;
	while (res[i])
		i++;
	return (i);
}

int	ft_chck(char **stock, char *check)
{
	int	i;

	i = 0;
	while(stock[i])
	{
		if (ft_strequ(stock[i], check))
			return (1);
		i++;
	}
	return (0);
}

void	ft_fill(char **res, char *look, char **stock, int *j)
{
	int i;

	i = 0;
	while (i < ft_nbtubes(res))
	{
		if (ft_tubestr(res[i], look) && !ft_chck(stock, ft_tubestr(res[i], look)))
{			
			stock[*j] = ft_tubestr(res[i], look);
			*j = *j + 1;
		
}
		i++;
	}
}

int	ft_verify(char *look, char *end, char **res)
{	
	char **stock;
	int i;
	int j;
	int so;

	j = 0;
	i = 0;
	stock = (char**)ft_memalloc(sizeof(char*) * (ft_nbtubes(res)));
	stock[i] = ft_strdup(look);
	i++;
	while (j < ft_nbtubes(res))
	{
		if (!stock[j])
			break ;
		ft_fill(res, stock[j], stock, &i);
		j++;
	}
	so = ft_chck(stock, end);
	i = 0;
	while (i < ft_nbtubes(res))
		ft_strdel(&stock[i++]);
	return (so);
}
