/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:31:03 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/03 18:34:01 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_initial_map(int c)
{
	int len;

	len = ft_sqrt(c * 4);
	return (len);
}

void		ft_free_tab(char **tetriso, char **map)
{
	int i;

	i = 0;
	while (tetriso[i])
		free(tetriso[i++]);
	free(tetriso);
	free(*map);
}

int			ft_(char **tetris, char ***tetriso, int c)
{
	if (c == 0)
	{
		free(*tetris);
		ft_putendl("error");
		return (0);
	}
	if (!(*tetriso = ft_split_nn(*tetris)))
	{
		free(tetris);
		ft_putendl("error");
		return (0);
	}
	free(*tetris);
	ft_letters(*tetriso, c);
	return (1);
}

int			main(int argc, char **argv)
{
	char	*tetris;
	char	*map;
	char	**tetriso;
	int		c;
	int		len;

	tetriso = NULL;
	if (!(tetris = ft_read(argc, argv)))
		return (0);
	c = test_input(tetris);
	if (!(ft_(&tetris, &tetriso, c)))
		return (0);
	if (!(len = ft_initial_map(c)) || len <= 0)
		return (0);
	if (!(map = map_generator(len)))
		return (0);
	while (ft_backtracking(&map, tetriso, 0, 0) == 0)
		if (!(ft_increase_map(&map, ++len)))
			return (0);
	ft_putendl(map);
	ft_free_tab(tetriso, &map);
	return (0);
}
