/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_nn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:26:48 by alac              #+#    #+#             */
/*   Updated: 2018/11/26 16:59:34 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_countletters(const char *s)
{
	int i;

	i = 0;
	while (!((s[i] == '\n' || s[i] == '\0') && s[i - 1] == '\n'))
		i++;
	return (i);
}

static int		ft_strlens(const char *s)
{
	int i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

static int		ft_cw(const char *s)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (i <= ft_strlens(s))
	{
		if ((s[i] == '\n' || s[i] == '\0') && (s[i - 1] == '\n'))
			count++;
		i++;
	}
	return (count);
}

static char		**ft_allocation(char const *s, char **tab)
{
	int		i;
	int		j;
	int		k;
	int		len;

	i = -1;
	j = 0;
	k = 0;
	len = 0;
	while (i++ < ft_strlens(s))
	{
		len = ft_countletters(&s[i]);
		if (s[i] != '\0')
		{
			if (!(tab[j] = (char *)malloc(sizeof(char) * (len + 1))))
				return (NULL);
			while (k < len)
				tab[j][k++] = s[i++];
			tab[j][k] = 0;
			k = 0;
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}

char			**ft_split_nn(char const *s)
{
	char **tab;

	if (s == NULL)
	{
		tab = NULL;
		return (tab);
	}
	if (!(tab = (char **)malloc(sizeof(tab) * (ft_cw(s) + 1))))
		return (NULL);
	return (ft_allocation(s, tab));
}
