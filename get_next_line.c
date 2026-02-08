/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:32:11 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/08 16:29:28 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*buf;
	int			nread;
	char		*ptr;
	char		*result;
	int			len;

	buf = malloc(sizeof(char) * (4 + 1));
	if (buf == NULL)
		return (NULL);
	nread = read(fd, buf, 4);
	if (nread <= 0)
		return (NULL);
	buf[nread] = '\0';
	ptr = ft_strchr(buf, '\n');
	if (ptr) // comprobamos si existe porque strchr devuelve NULL si no encuentra \n
	{
		len = ptr - buf + 1;
		result = ft_substr(buf, len);
		free(saved);
		saved = ft_strdup(ptr + 1);
	}
	else
	{
		if (saved != NULL)
			result = ft_strjoin(saved, buf);
		else
			result = ft_strdup(buf);
	}
	return (result);
}
/*
int	main(void)
{
	int	fd;

	fd = open("prueba.txt", O_RDWR);
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
*/