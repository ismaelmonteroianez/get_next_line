/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:00:26 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/14 18:24:15 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	len = ft_strlen(str);
	copy = malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char *str, int len)
{
	int		i;
	char	*substr;

	i = 0;
	substr = malloc(sizeof (char) * len + 1);
	if (substr == NULL)
		return (NULL);
	while (len > i)
	{
		substr[i] = str[i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*sjoin;

	if (!s1)
		return (ft_strdup(s2));
	sjoin = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (sjoin == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		sjoin[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		sjoin[i] = s2[j];
		i++;
		j++;
	}
	sjoin[i] = '\0';
	return (sjoin);
}
