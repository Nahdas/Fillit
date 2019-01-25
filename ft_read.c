/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:04:26 by alac              #+#    #+#             */
/*   Updated: 2018/12/03 18:29:48 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*ft_strjoin_fr(char *s1, char *s2)
{
	char *str;

	if (!s1)
	{
		str = ft_strdup(s2);
		return (str);
	}
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	str = ft_strcpy(str, s1);
	str = ft_strncat(str, s2, ft_strlen(s2));
	return (str);
}

static int		ft_read_file(const int fd, char **str)
{
	int		ret;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

	*str = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) && ret > 0)
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin_fr(*str, buff)))
			return (-1);
		free(*str);
		*str = tmp;
		if (ft_strlen(*str) > 546)
		{
			ft_strdel(str);
			return (-1);
		}
	}
	return (ret);
}

char			*ft_read(int argc, char **argv)
{
	char	*str;
	int		fd;

	if (argc != 2)
	{
		ft_putstr_fd("usage: ./fillit source_file\n", 1);
		return (NULL);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("error\n", 1);
		return (NULL);
	}
	if (ft_read_file(fd, &str) == -1 || close(fd) == -1)
	{
		ft_putstr_fd("error\n", 1);
		return (NULL);
	}
	if (str != '\0')
		return (str);
	ft_putstr_fd("error\n", 1);
	return (NULL);
}
