/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:32:11 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/14 18:22:06 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
void	*ft_free(char **buf, char **stored)
{
	if (*buf != NULL)
		free(*buf);
	*buf = NULL;
	if (*stored != NULL)
		free(*stored);
	*stored = NULL;
	return (NULL);
}
*/
char	*ft_getline(char *stored, char *ptr_nl)
{
	char	*line;
	int		pos;

	pos = ptr_nl - stored + 1;
	line = ft_substr(stored, pos);
	return (line);
}

char	*ft_read(int fd, char *stored)
{
	int		bytes_read;
	char	*buf;
	char	*aux;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (!stored || !ft_strchr(stored, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buf);
			free(stored);
			stored = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
		{
			free(buf);
			buf = NULL;
			return (stored);
		}
		buf[bytes_read] = '\0';
		aux = stored;
		stored = ft_strjoin(stored, buf);
		free(aux);
		if (!stored)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (stored);
}

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*ptr_nl;
	char		*line;
	char		*aux;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stored = ft_read(fd, stored);
	if (!stored)
		return (NULL);
	ptr_nl = ft_strchr(stored, '\n');
	if (ptr_nl)
	{
		line = ft_getline(stored, ptr_nl);
		aux = ft_substr(ptr_nl + 1, ft_strlen(ptr_nl + 1));
		free(stored);
		if (!aux)
		{
			free(aux);
			stored = NULL;
		}
		if (aux && *aux != '\0')
			stored = aux;
		else
    	{
        	free(aux);
        	stored = NULL;
    	}
		return (line);
	}
	else
	{
		if (stored && *stored != '\0')
		{
			line = ft_strdup(stored);
			free(stored);
			stored = NULL;
			return (line);
		}
	}
	if (stored)
	{
		free(stored);
		stored = NULL;
	}
	return (NULL);
}
/*
int	main(void)
{
	int	fd;
	char *line;

	fd = open("prueba.txt", O_RDWR);

	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
*/
/*
int	main(void)
{
	int	fd;

	fd = open("prueba.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
*/
/*
int	main(void)
{
	int	fd;

	fd = open("prueba.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	
	
}
*/