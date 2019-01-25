/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:40:31 by alac              #+#    #+#             */
/*   Updated: 2018/12/03 14:58:27 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_is_available(int k, char *copy, int len, int x)
{
	if (k == 1)
	{
		if (copy[x + 1] == '.')
			return (x + 1);
		return (-1000);
	}
	if (k > 1)
	{
		x = x + len - (5 - k);
		if (copy[x] == '.')
			return (x);
		return (-1000);
	}
	return (-1000);
}

int		ft_next_block(char *piece, int k)
{
	k++;
	while (piece[k] == '.' || piece[k] == '\n')
		k++;
	if (piece[k] == '\0')
		return (-1);
	return (k);
}

int		ft_try_position(char *piece, char *copy, int len, int x)
{
	int	blocks;
	int k;
	int l;

	blocks = 0;
	k = 0;
	while (blocks < 3)
	{
		l = k;
		k = ft_next_block(piece, k);
		if ((x = ft_is_available(k - l, copy, len, x)) && x >= 0
				&& x < len * (len - 1))
		{
			copy[x] = piece[k];
			blocks++;
		}
		else
			return (0);
	}
	return (1);
}

int		ft_is_free(char *piece, char *copy, int j, int len)
{
	int k;

	k = 0;
	if (copy[j] == '.' && j < len)
	{
		copy[j] = piece[k];
		return (j);
	}
	return (-1000);
}

int		ft_put_tetris(char *piece, char **map, int j, int index_piece)
{
	int		x;
	int		k;
	char	*copy;
	int		len;

	x = 0;
	k = -1;
	ft_remove_piece(index_piece, *map);
	copy = ft_strdup(*map);
	len = (int)ft_strclen(copy, '\n');
	k = ft_next_block(piece, k);
	x = ft_is_free(&piece[k], &copy[x], j, (int)ft_strlen(copy));
	if (x >= 0 && ft_try_position(&piece[k], copy, len + 1, x) == 1)
	{
		ft_strdel(map);
		*map = ft_strdup(&copy[x - x]);
		ft_strdel(&copy);
		return (1);
	}
	ft_strdel(&copy);
	ft_remove_piece(index_piece, *map);
	ft_strdel(&copy);
	return (0);
}
