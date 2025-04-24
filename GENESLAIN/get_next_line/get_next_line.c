/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:38:27 by marcoga2          #+#    #+#             */
/*   Updated: 2025/04/24 16:06:57 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include "get_next_line.h"
#include <stdio.h>

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
	if (s[i] == '\n')
		result = string_join(result, "\n");
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

char	*read_til_n(int fd, char *save, int *is_empty)
{
	int		chars_num;
	char	*buffer;
	int		i;

	i = 0;
	if (!save)
		save = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	chars_num = 1;
	while (chars_num > 0)
	{
		chars_num = read(fd, buffer, BUFFER_SIZE);
		if (chars_num != 0)
			is_empty = 0;
		if (chars_num < 1)
		{
			free(buffer);
			if (chars_num == 0 && !is_empty)
				return (save);
			free(save);
			return (NULL);
		}
		save = string_join(save, buffer);
		while (i < BUFFER_SIZE)
			buffer[i++] = '\0';
		if (linelen_mode(save, 3) == 1)
			break ;
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	static int	is_empty;
	char		*line;
	char		*temp;

	is_empty = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save || !linelen_mode(save, 3))
	{
		save = read_til_n(fd, save, &is_empty);
		if (save == NULL || linelen_mode(save, 1) == 0)
			return (NULL);
	}
	line = copy_til_n(save);
	temp = clear_til_n(save);
	free(save);
	save = temp;
	return (line);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		a;
// 	char	*line;
// 	int		i;

// 	a = open("../../../francinette/tests/get_next_line/gnlTester/files/43_with_nl",
// 			O_RDONLY);
// 	if (!a)
// 	{
// 		perror("Error abriendo el archivo\n");
// 		return (1);
// 	}
// 	printf("archivo leido\n");
// 	i = 0;
// 	while ((line = get_next_line(a)) != NULL)
// 	{
// 		printf("%s", line);
// 		sleep(1);
// 		free(line);
// 		i++;
// 	}
// 	if (line == NULL)
// 		printf("NULO");
// 	close(a);
// 	return (0);
// }

// printf("----------------------------------\n");
// printf("la línea : \n %s \n contiene %d ENE\n", result,
// printf("----------------------------------\n");
