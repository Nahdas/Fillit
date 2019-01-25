/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:14:36 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/03 14:46:29 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*map_generator(int n)
{
	char	*map;
	int		i;

	i = 1;
	if (!(map = ft_strnew(n * (n + 1) + 1)))
		return (NULL);
	while (i < n * (n + 1))
	{
		if ((i % (n + 1)) == 0)
			map[i - 1] = '\n';
		else
			map[i - 1] = '.';
		i++;
	}
	map[i - 1] = '\0';
	return (map);
}
