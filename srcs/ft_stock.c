/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:53:24 by alecott           #+#    #+#             */
/*   Updated: 2018/03/05 17:15:47 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	ft_isroomprev(char *str, size_t *i, size_t *x)
{
	if (str[*i] == ' ')
	{
		*x = *x + 1;
		*i = *i + 1;
	}
	while (str[*i] && ft_isdigit(str[*i]))
		*i = *i + 1;
	if (str[*i] == ' ')
	{
		*x = *x + 1;
		*i = *i + 1;
	}
}

static int	ft_isroom(char *str)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (str == NULL || str[0] == 0)
		return (0);
	if (str[0] == '#')
		return (1);
	if (str[0] == 'L')
		return (0);
	while (str[i] && ft_isprint(str[i]) && str[i] != '-' && str[i] != ' ')
		i++;
	ft_isroomprev(str, &i, &x);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (i != ft_strlen(str) || x != 2)
		return (0);
	return (1);
}

static int	ft_istubes(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (str[0] == '#')
		return (1);
	while (ft_isprint(str[i]))
	{
		if (str[i] == '-')
			n++;
		i++;
	}
	if (n == 1)
		return (1);
	return (0);
}

static int	ft_stock_tubes(t_ants *info, char *line)
{
	int		i;
	int		n;

	n = 2;
	i = 0;
	info->tubes = (char**)ft_memalloc(sizeof(char*) * (n + 1));
	while (ft_istubes(line))
	{
		info->tubes[i] = line;
		line = 0;
		if (get_next_line(0, &line) <= 0)
		{
			info->tubes[i + 1] = NULL;
			ft_strdel(&line);
			return (1);
		}
		n++;
		info->tubes = ft_realloc(info->tubes,
sizeof(char *) * n, sizeof(char *) * (n + 1));
		i++;
	}
	ft_strdel(&line);
	return (0);
}

int			ft_stock(t_ants *info)
{
	char	*line;
	int		i;
	int		n;

	n = 1;
	i = 0;
	get_next_line(0, &line);
	info->nb_ant = ft_atoi(line);
	ft_strdel(&line);
	info->rooms = (char**)ft_memalloc(sizeof(char*) * (n + 1));
	while (get_next_line(0, &line) > 0 && ft_isroom(line))
	{
		info->rooms[i] = line;
		line = 0;
		n++;
		info->rooms = ft_realloc(info->rooms,
sizeof(char *) * n, sizeof(char *) * (n + 1));
		i++;
	}
	info->rooms[i] = NULL;
	i = 0;
	return (ft_stock_tubes(info, line));
}
