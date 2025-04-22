/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:38:27 by marcoga2          #+#    #+#             */
/*   Updated: 2025/04/22 13:03:25 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*copy_til_n(char *s)
{
	char	*result;
	size_t	len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = linelen_mode(s, 2);
	result = (char *)ft_calloc(sizeof(char), len + 1);
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}

char	*clear_til_n(char *s)
{
	char	*result;
	size_t	len;
	size_t	i;

	i = 0;
	while (*s && *s != '\n')
		s++;
	if (*s == '\n')
		s++;
	len = linelen_mode(s, 1);
	result = (char *)ft_calloc(sizeof(char), len + 1);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}

char	*read_til_n(int fd, char *save)
{
	int		chars_num;
	char	*buffer;

	if (!save)
		save = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	chars_num = 1;
	while (chars_num > 0)
	{
		chars_num = read(fd, buffer, BUFFER_SIZE);
		if (chars_num < 1)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		save = string_join(save, buffer);
		if (linelen_mode(save, 3) == 1)
			break ;
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*temp;

	if (read(fd, 0, 0) < 0 || fd < 0)
		return (NULL);
	save = read_til_n(fd, save);
	if (save == NULL)
		return (NULL);
	line = copy_til_n(save);
	temp = clear_til_n(save);
	free(save);
	save = temp;
	return (line);
}
