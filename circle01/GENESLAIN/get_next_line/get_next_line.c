/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:38:27 by marcoga2          #+#    #+#             */
/*   Updated: 2025/04/28 11:38:30 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clear_from_n(char *save)
{
	char	*new_save;
	int		len;

	if (!linelen_mode(3, save))
		return (super_free(&save));
	else
		len = linelen_mode(2, save) + 1;
	if (!save[len])
		return (super_free(&save));
	new_save = ft_substr(save, len, linelen_mode(1, save) - len);
	super_free(&save);
	if (!new_save)
		return (NULL);
	return (new_save);
}

char	*read_til_n(int fd, char *save)
{
	int		chars_num;
	char	*buffer;

	chars_num = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (super_free(&save));
	buffer[0] = '\0';
	while (chars_num > 0 && !linelen_mode(3, buffer))
	{
		chars_num = read (fd, buffer, BUFFER_SIZE);
		if (chars_num > 0)
		{
			buffer[chars_num] = '\0';
			save = ft_strjoin(save, buffer);
		}
	}
	free(buffer);
	if (chars_num == -1)
		return (super_free(&save));
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save = {0};
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((save && !linelen_mode(3, save)) || !save)
		save = read_til_n(fd, save);
	if (!save)
		return (NULL);
	line = ft_substr(save, 0, linelen_mode(2, save) + 1);
	if (!line)
		return (super_free(&save));
	save = clear_from_n(save);
	return (line);
}
