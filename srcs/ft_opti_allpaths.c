/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti_allpaths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 08:50:08 by alecott           #+#    #+#             */
/*   Updated: 2018/04/30 16:32:31 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char	*ft_strnmdup(char *str, int start, int end)
{
	char	*clone;
	int		i;

	i = 0;
	clone = (char*)ft_memalloc(sizeof(char) * (end - start + 1));
	while (start < end)
	{
		clone[i] = str[start];
		start++;
		i++;
	}
	return (clone);
}

int		ft_exist(char *path, char *savepath)
{
	int 	i;
	int 	j;
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


char		*ft_add_in_path(char *path, char *savepath, t_ants info)
{
	int 	i;
	int 	j;
	char	*tmp;
	char	*tmpp;

	i = 0;
	j = 0;
	tmp = NULL;
	while (path[i])
	{
		j = i;
		while (path[i] && path[i] != '-')
			i++;
		if (tmp)
			ft_strdel(&tmp);
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
			ft_strdel(&tmpp);
			ft_strdel(&tmp);
		}
		i++;
	}
	return (savepath);
}

char	**ft_opti_allpaths(t_ants *info, char **path)
{
	int 	i;
	int 	j;
	char	*savepath;
	char	**pathopti;

	i = 0;
	j = 0;
	while (path[i])
		i++;
	pathopti = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	i = 0;
	savepath = NULL;
	while (path[i])
	{
		if (!(ft_exist(path[i], savepath)))
		{
			pathopti[j++] = ft_strdup(path[i]);
			savepath = ft_add_in_path(path[i++], savepath, *info);
		}
		else
			ft_strdel(&path[i++]);
	}
	ft_strdel(&savepath);
	return (pathopti);
}
