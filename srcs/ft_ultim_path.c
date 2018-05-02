/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultim_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 10:51:05 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/02 13:08:18 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		ft_nb_element(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	ft_memdel((void**)tab);
}

char	**ft_add_clone_and_path(char *path, char **clone)
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

char	*ft_add_in_path2(char *path, char *savepath, t_ants info)
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
			return (savepath);
		}
		if (savepath == NULL)
			savepath = ft_strdup(tmp);
		else
		{
			tmpp = savepath;
			savepath = ft_strjoin(tmpp, "-");
			ft_strdel(&tmpp);
			tmpp = savepath;
			savepath = ft_strjoin(tmpp, tmp);
		}
		ft_strdel(&tmp);
		ft_strdel(&tmpp);
		i++;
	}
	return (savepath);
}

void	ft_ultim_path(t_ants *info, char **path)
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
		final = ft_add_clone_and_path(path[i], clone);
		free(clone);
		nb_path = ft_nb_element(final);
		if (nb_path > info->nb_repeat)
		{
			info->nb_repeat = nb_path;
			info->ultim_path = ft_copy_tab(final);
		}
		ft_free_tab(final);
		free(final);
		i++;
	}
}
