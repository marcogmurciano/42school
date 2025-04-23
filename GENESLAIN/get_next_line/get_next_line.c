/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:38:27 by marcoga2          #+#    #+#             */
/*   Updated: 2025/04/23 16:04:03 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

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

	while (*s && *s != '\n')
		s++;
	if (*s == '\0')
		return (NULL);
	s++;
	len = linelen_mode(s, 1);
	result = (char *)ft_calloc(sizeof(char), len + 1);
	if (!result)
		return (NULL);
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
	if (!buffer)
		return (NULL);
	chars_num = 1;
	while (chars_num > 0)
	{
		chars_num = read(fd, buffer, BUFFER_SIZE);
		if (chars_num < 1)
		{
			free(buffer);
			// if (chars_num == 0)
			// 	return (save);
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save || !linelen_mode(save, 3))
	{
		save = read_til_n(fd, save);
		if (save == NULL || linelen_mode(save, 1) == 0)
			return (NULL);
	}
	line = copy_til_n(save);
	temp = clear_til_n(save);
	free(save);
	save = temp;
	return (line);
}

#include <string.h>
#include <stdio.h>

void print_color(const char *text, const char *color) {
    // Definimos códigos de color ANSI
    const char *reset = "\033[0m";
    const char *red = "\033[31m";
    const char *green = "\033[32m";
    const char *yellow = "\033[33m";
    const char *blue = "\033[34m";
    const char *magenta = "\033[35m";
    const char *cyan = "\033[36m";
    const char *white = "\033[37m";

    const char *selected_color = reset; // Por defecto

    // Seleccionar el color
    if (color != NULL) {
        if (strcmp(color, "red") == 0) selected_color = red;
        else if (strcmp(color, "green") == 0) selected_color = green;
        else if (strcmp(color, "yellow") == 0) selected_color = yellow;
        else if (strcmp(color, "blue") == 0) selected_color = blue;
        else if (strcmp(color, "magenta") == 0) selected_color = magenta;
        else if (strcmp(color, "cyan") == 0) selected_color = cyan;
        else if (strcmp(color, "white") == 0) selected_color = white;
    }

    printf("%s%s%s\n", selected_color, text, reset);
}

int	main(void)
{
	int		a = open("../../../francinette/tests/get_next_line/gnlTester/files/41_no_nl", O_RDONLY);
	char	*line;

	if (a == -1)
	{
		perror("Error abriendo el archivo\n");
		return (1);
	}
	printf("archivo leido\n");
	while ((line = get_next_line(a)) != NULL)
	{
		print_color(line, "blue");
		sleep(1);
		free(line);
	}
	close(a);
	return (0);
}
