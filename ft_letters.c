/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:26:57 by alac              #+#    #+#             */
/*   Updated: 2018/12/02 09:20:32 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_letters(char **tab, int pieces)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (i < (size_t)pieces)
	{
		while (j < ft_strlen(tab[i]))
		{
			if (tab[i][j] == '#')
				tab[i][j] = 'A' + k;
			j++;
		}
		j = 0;
		i++;
		k++;
	}
}
