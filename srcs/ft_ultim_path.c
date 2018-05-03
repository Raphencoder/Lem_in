/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultim_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 10:51:05 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/03 14:42:43 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static char		**ft_add_clone_and_path(char *path, char **clone)
{
	char	**final;
	int		i;
	int		j;

	j = 0;
	i = ft_nb_element(clone);
	final = (char**)ft_memalloc(sizeof(char*) * (i + 2));
	final[0] = ft_strdup(path);
	i = 1;
	while (clone[j])
	{
		final[i] = ft_strdup(clone[j]);
		i++;
		j++;
	}
	ft_free_tab(clone);
	return (final);
}

static void		ft_next_add(char **savepath, char *tmp, char *tmpp, int *i)
{
	if (*savepath == NULL)
		*savepath = ft_strdup(tmp);
	else
	{
		tmpp = *savepath;
		*savepath = ft_strjoin(tmpp, "-");
		ft_strdel(&tmpp);
		tmpp = *savepath;
		*savepath = ft_strjoin(tmpp, tmp);
	}
	ft_strdel(&tmp);
	ft_strdel(&tmpp);
	*i = *i + 1;
}

static char		*ft_add_in_path2(char *path, char *savepath, t_ants info)
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
			if (savepath == NULL)
				savepath = ft_strdup(info.end);
			return (savepath);
		}
		ft_next_add(&savepath, tmp, tmpp, &i);
	}
	return (savepath);
}

static void		ft_ultim_next(char **c, char **f, int nb_path, t_ants *info)
{
	free(c);
	nb_path = ft_nb_element(f);
	if (nb_path > info->nb_repeat)
	{
		info->nb_repeat = nb_path;
		if (info->ultim_path != NULL)
		{
			ft_free_tab(info->ultim_path);
			free(info->ultim_path);
		}
		info->ultim_path = ft_copy_tab(f);
	}
	ft_free_tab(f);
	free(f);
}

void			ft_ultim_path(t_ants *info, char **path)
{
	int		i;
	int		nb_path;
	char	*savepath;
	char	**clone;
	char	**final;

	i = 0;
	info->nb_repeat = -1;
	info->ultim_path = NULL;
	savepath = NULL;
	while (path[i])
	{
		nb_path = 0;
		savepath = ft_add_in_path2(path[i], NULL, *info);
		if (savepath == NULL)
		{
			i++;
			continue;
		}
		clone = ft_opti_allpaths(info, path, &savepath);
		ft_strdel(&savepath);
		final = ft_add_clone_and_path(path[i++], clone);
		ft_ultim_next(clone, final, nb_path, info);
	}
}
