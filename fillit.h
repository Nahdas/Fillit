/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:32:40 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/05 16:56:49 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

int						ft_remove_piece(int index_piece, char *copy);
int						test_input(char *tetris);
int						ft_increase_map(char **map, int len);
int						ft_put_tetris(char *piece, char **map, int j, int i);
void					ft_letters(char **tab, int pieces);
char					**ft_split_nn(const char *s);
char					*map_generator(int n);
char					*ft_read(int argc, char **argv);
int						ft_backtracking(char **map,
		char **tetriso, int i, int j);

# define BUFF_SIZE 32

#endif
