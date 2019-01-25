/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:33:21 by alac              #+#    #+#             */
/*   Updated: 2018/12/05 10:33:30 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_pieces(char **tetriso)
{
	int i;

	i = 1;
	while (tetriso[i])
		i++;
	return (i);
}

int				ft_remove_piece(int index_piece, char *copy)
{
	int i;

	i = 0;
	while (copy[i])
	{
		if (copy[i] >= 'A' + index_piece)
			copy[i] = '.';
		i++;
	}
	return (0);
}

int				ft_increase_map(char **map, int len)
{
	ft_strdel(map);
	if (!(*map = map_generator(len)))
		return (0);
	return (len);
}

int				ft_backtracking(char **map, char **tetriso, int i, int j)
{
	int c;

	c = ft_pieces(tetriso);
	if (i == c)
		return (1);
	j = -1;
	while (++j < (int)ft_strlen(*map))
	{
		if (ft_put_tetris(tetriso[i], map, j, i) == 1)
		{
			if (ft_backtracking(map, tetriso, ++i, j) == 1)
				return (1);
			ft_remove_piece(i - 1, *map);
			i--;
		}
	}
	return (0);
}
