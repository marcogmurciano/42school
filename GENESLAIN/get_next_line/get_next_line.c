/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:38:27 by marcoga2          #+#    #+#             */
/*   Updated: 2025/04/18 13:06:21 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 42
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stddef.h>
#include <string.h>

size_t	linelen_mode(const char *s, int mode)
{
	size_t	i;
	
	if (mode == 1)
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		return (i);
	}
	else if (mode == 2)
	{
		i = 0;
		while (s[i] != '\0' || s[i] != '\n')
			i++;
		return (i);
	}
	else if (mode == 3)
	{
		i = 0;
		while (s[i] != '\n')
			i++;
		return (i);
	}
	return (0);
}

char	*string_join(char *save, char *temp)
{
	char	*new;
	size_t	save_len;
	size_t	temp_len;
	int		i;

	save_len = linelen_mode(save, 1);
	temp_len = linelen_mode(temp, 1);
	new = (char *)malloc(save_len + temp_len + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < save_len)
		new[i] = save[i];
	i = -1;
	while (++i < temp_len + 1)
		new[i + save_len] = temp[i];
	free(save);
	return (new);
}

char	*read_until_enter(int fd, char *save)
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
		if (chars_num == -1)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[chars_num] = '\0';
		save = string_join(save, buffer);
		if (ft_strchr(save, '\n'))
			break ;
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (read(fd, 0, 0) < 0 || fd < 0)
		return (NULL);
	save = read_until_enter(fd, save);
	if (save == NULL)
		return (NULL);
	line = create_line(save);
	save = the_rest(save);
	return (line);
}
