/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:57:17 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/22 10:01:33 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c ,1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);;
		i++;
	}
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
	printf("%d\n", ft_check_ifexist("à", "1-2-3-4-5-t-2-à"));
	return (0);
}
