/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:57:17 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/24 16:38:25 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

void	ft_putchar(char c)
{
	write(1, &c ,1);
}

int     ft_check_ifexist(char *room, char *path)
{
        int i;
        int j;

        i = 0;
        j = 0;
        while (path[i])
        {
                if (room[j] == path[i])
                {
                        while (path[i] != '-' && room[j] && room[j] == path[i])
                        {
                                j++;
                                i++;
                        }
                        if (!room[j] && (path[i] == '-' || !path[i]))
                                return (1);
                }
                j = 0;
                while (path[i] && path[i] != '-')
                        i++;
                i++;
        }
        return (0);
}

int main()
{
	char *path;
	char *room;

	path = ft_strdup("0-2");
	room = ft_strdup("8");	
	printf("%d\n", ft_check_ifexist(room, path));
	return (0);
}
