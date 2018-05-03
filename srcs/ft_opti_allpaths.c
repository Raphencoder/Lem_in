/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti_allpaths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 08:50:08 by alecott           #+#    #+#             */
/*   Updated: 2018/05/03 14:17:22 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int		ft_exist(char *path, char *savepath)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	if (savepath == NULL)
		return (0);
	while (path[i])
	{
		j = i;
		while (path[i] && path[i] != '-')
			i++;
		tmp = ft_strnmdup(path, j, i);
		if (ft_check_ifexist(tmp, savepath))
		{
			ft_strdel(&tmp);
			return (1);
		}
		ft_strdel(&tmp);
		i++;
	}
	return (0);
}

static void		ft_next(char *tmpp, char ***savepath, char *tmp, int *i)
{
	tmpp = **savepath;
	**savepath = ft_strjoin(tmpp, "-");
	ft_strdel(&tmpp);
	tmpp = **savepath;
	**savepath = ft_strjoin(tmpp, tmp);
	ft_strdel(&tmp);
	ft_strdel(&tmpp);
	*i = *i + 1;
}

static char		*ft_add_in_path(char *path, char **savepath, t_ants info)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmpp;

	i = 0;
	j = 0;
	tmp = NULL;
	tmpp = NULL;
	while (path[i])
	{
		j = i;
		while (path[i] && path[i] != '-')
			i++;
		tmp = ft_strnmdup(path, j, i);
		if (ft_strequ(tmp, info.end))
		{
			ft_strdel(&tmp);
			return (*savepath);
		}
		ft_next(tmpp, &savepath, tmp, &i);
	}
	return (*savepath);
}

char			**ft_opti_allpaths(t_ants *info, char **path, char **savepath)
{
	int		i;
	int		j;
	char	*tmp;
	char	**pathopti;

	i = 0;
	j = 0;
	tmp = NULL;
	while (path[i])
		i++;
	pathopti = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	i = 0;
	while (path[i])
	{
		if (!(ft_exist(path[i], *savepath)))
		{
			pathopti[j++] = ft_strdup(path[i]);
			ft_add_in_path(path[i++], savepath, *info);
		}
		else
			i++;
	}
	return (pathopti);
}
