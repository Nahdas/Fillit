/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:07:20 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/03 16:16:51 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			test_bloc(char *tetris)
{
	int i;
	int c;

	c = 0;
	i = 1;
	while (tetris[i + c])
	{
		if (i % 20 == 0)
		{
			if (tetris[i + c] == '\n' || tetris[i + c] == '\0')
				c++;
			else
				return (0);
		}
		if (c > 25)
			return (0);
		i++;
	}
	if (c == 0 && i == 20)
		return (1);
	if (i % 20 == 0 && tetris[i + c] == '\0')
		return (c + 1);
	return (0);
}

int			test_line(char *tetris)
{
	int i;
	int c;

	c = -1;
	i = 1;
	while (tetris[i + c])
	{
		if (i % 5 == 0)
		{
			if (tetris[i + c] != '\n')
				return (0);
			if (tetris[i + c + 1] == '\n')
				c++;
		}
		i++;
	}
	return (1);
}

int			part_test_tetris(char *tetris, int i, int mul, int *l)
{
	int b;

	if (tetris[i + mul * 21] == '#')
	{
		b = *l;
		if (i + (mul * 21) >= 1 && tetris[(i + (mul * 21)) - 1] == '#')
			(*l)++;
		if (tetris[i + (mul * 21) + 1] == '#')
			(*l)++;
		if (i >= 5 && tetris[(i + (mul * 21)) - 5] == '#')
			(*l)++;
		if (i < 15 && tetris[(i + (mul * 21)) + 5] == '#')
			(*l)++;
		if (*l == b)
			return (0);
	}
	return (1);
}

int			test_tetris(char *tetris, int c)
{
	int i;
	int l;
	int mul;

	mul = -1;
	while (++mul <= c)
	{
		l = 0;
		i = 0;
		while (i < 21)
		{
			if (!(part_test_tetris(tetris, i, mul, &l)))
				return (0);
			i++;
		}
		if (l != 6 && l != 8)
			return (0);
	}
	return (1);
}

int			test_input(char *tetris)
{
	int i;
	int c;

	i = 0;
	if (!tetris)
		return (0);
	while (tetris[i])
	{
		if (tetris[i] != '\n' && tetris[i] != '#' && tetris[i] != '.')
			return (0);
		i++;
	}
	c = test_bloc(tetris);
	if (c == 0)
		return (0);
	if (!test_line(tetris))
		return (0);
	if (!test_tetris(tetris, c - 1))
		return (0);
	return (c);
}
