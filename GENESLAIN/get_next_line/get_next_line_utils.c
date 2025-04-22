/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:38:18 by marcoga2          #+#    #+#             */
/*   Updated: 2025/04/22 13:03:35 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	linelen_mode(const char *s, int mode)
{
	size_t	i;

	i = 0;
	if (mode == 1)
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
	else if (mode == 2)
	{
		while (s[i] != '\0' && s[i] != '\n')
			i++;
		return (i);
	}
	else if (mode == 3)
	{
		while (s[i] != '\0')
		{
			if (s[i] == '\n')
				return (1);
			i++;
		}
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

void	*ft_calloc(size_t size, size_t amount)
{
	char	*result;
	char	*s;
	size_t	i;

	i = 0;
	result = malloc(size * amount);
	if (!result)
		return (NULL);
	s = (char *)result;
	while (i < size * amount)
	{
		s[i] = '\0';
		i++;
	}
	return (result);
}
