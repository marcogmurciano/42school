/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:38:18 by marcoga2          #+#    #+#             */
/*   Updated: 2025/04/23 15:30:03 by marcoga2         ###   ########.fr       */
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

char	*partial_join(char *save, char *temp)
{
	char	*new;
	size_t	i;
	size_t	s_len;
	size_t	t_len;

	i = 0;
	s_len = linelen_mode(save, 1);
	t_len = linelen_mode(temp, 1);
	new = ft_calloc(s_len + t_len + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (i < s_len)
	{
		new[i] = save[i];
		i++;
	}
	i = 0;
	while (i < t_len + 1)
	{
		new[i + s_len] = temp[i];
		i++;
	}
	return (new);
}

char	*string_join(char *save, char *temp)
{
	char	*new;

	if (!save)
		save = ft_calloc(1, 1);
	if (!temp)
		return (save);
	new = partial_join(save, temp);
	if (!new)
		return (NULL);
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
