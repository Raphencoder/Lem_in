/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 10:13:35 by alecott           #+#    #+#             */
/*   Updated: 2018/05/03 14:43:30 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_ants
{
	char	**rooms;
	char	**tubes;
	char	**tubes_names;
	char	**names;
	char	*start;
	char	*end;
	char	*room;
	char	*rm;
	char	*path;
	char	**tmpp;
	char	*tmp;
	char	**tmp1;
	char	**ultim_path;
	int		nb_repeat;
	int		l;
	int		k;
	int		j;
	int		m;
	int		nb_room;
	int		nb_tubes;
	int		nb_ant;
	char	**room_ant;
	char	**path_ant;
}				t_ants;

void			ft_lem_in(t_ants *info);
int				ft_stock(t_ants *info);
void			ft_names(t_ants *info);
int				ft_error(t_ants *info);
char			*ft_link(char *room, char *tube, t_ants *info);
int				ft_room_number(t_ants *info, char *room);
int				ft_norm(t_ants *info, int *i, int *j, int *n);
int				ft_check_ant(t_ants *info, char *room);
int				ft_tubestr(char *s1, char *s2);
int				ft_verify(char *look, char *end, t_ants *info);
void			ft_fill_path(t_ants *info);
void			ft_move_tubes(char **tubes);
void			ft_feel_free(t_ants *info, char **clonepath);
char			*ft_rm_last_one(char *path);
void			ft_sort_tubes_and_repeat(t_ants *info, int *i);
char			*ft_get_room(char *room, char *link);
int				ft_find_room_intube(char *room, char *link);
char			*ft_get_last_inpath(char *path);
char			*ft_complete_path(char *path, char *room, int i, t_ants info);
int				ft_check_ifexist(char *room, char *path);
void			ft_add_and_delete(t_ants *info, char **allpath);
int				ft_check_path(char *path, char **allpath);
void			ft_find_nbroom(t_ants *info);
char			*ft_remove_ifrepeat(char *rm, int *m, char *path, char *room);
void			ft_choose_nbofrm(int *clonem, t_ants *info);
void			ft_find_nb_tubes(t_ants *info);
void			ft_algo(t_ants *info, char **path);
void			ft_tubes_names(t_ants *info);
int				ft_nbrooms_in_path(char *path);
char			**ft_sort_paths(char **path);
char			*ft_sub_path(char *path);
char			**ft_opti_allpaths(t_ants *info, char **path, char **savepath);
void			ft_free_all(char **path, t_ants *info);
char			*ft_take_room(char *path);
void			ft_ultim_path(t_ants *info, char **path);
void			ft_nextoffind(t_ants *info, char **path);
void			ft_free_tab(char **tab);
int				ft_nb_element(char **tab);
#endif
