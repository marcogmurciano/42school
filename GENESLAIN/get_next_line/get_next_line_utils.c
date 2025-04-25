/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:38:18 by marcoga2          #+#    #+#             */
/*   Updated: 2025/04/25 17:48:04 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = (char *)malloc(linelen_mode(1, s1) + linelen_mode(1, s2) + 1);
	if (!str)
		return (super_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t fragment_len)
{
	size_t	i;
	size_t	total_len;
	char	*result;

	i = 0;
	total_len = linelen_mode(1, s);
	if (!s)
		return (0);
	if (start > total_len)
	{
		result = malloc(sizeof(char) * (1));
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (total_len - start < fragment_len)
		fragment_len = linelen_mode(1, s) - start;
	result = malloc(sizeof(char) * (fragment_len + 1));
	if (!result)
		return (NULL);
	while (start < total_len && i < fragment_len && s[start])
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}

size_t	linelen_mode(int mode, const char *s)
{
	size_t	i;
	char	c;

	i = 0;
	c = '\0';
	if (!s)
		return (0);
	if (mode == 1 || mode == 2)
	{
		if (mode == 2)
			c = '\n';
		while (s[i] != '\0' && s[i] != c)
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

char	*super_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
