/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:27:23 by user              #+#    #+#             */
/*   Updated: 2025/04/17 17:31:53 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	chars_count(char const *str, int wich, int c)
{
	int	i;
	int	fragment_count;
	int	split_chars;

	i = 0;
	fragment_count = 0;
	split_chars = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if (split_chars == wich)
			return (fragment_count);
		if (split_chars == wich - 1 && str[i] != c)
			fragment_count++;
		if (str[i] == c && str[i - 1] != c)
			split_chars++;
		i++;
	}
	if (split_chars == wich - 1)
		return (fragment_count);
	return (fragment_count);
}

int	bad_gateway(char **strings, int count)
{
	while (count-- > 0)
	{
		free(strings[count]);
		strings[count] = NULL;
	}
	return (1);
}
//ñapa en while ++j;

int	fill_strings(char **strings, char const *s, char c, int w)
{
	int	i;
	int	j;
	int	substr_len;
	int	already_read;

	i = 0;
	already_read = 0;
	while (s[already_read] == c)
		already_read++;
	while (i < w)
	{
		j = -1;
		substr_len = chars_count(s, i + 1, c);
		strings[i] = malloc(sizeof(char) * (substr_len + 1));
		if (!strings[i])
			return (bad_gateway(strings, i));
		while (++j < substr_len)
			strings[i][j] = s[already_read + j];
		strings[i++][j] = '\0';
		already_read = already_read + j;
		while (s[already_read] == c)
			already_read++;
	}
	strings[i] = NULL;
	return (0);
}

int	how_many_words(char *str, char c)
{
	int	i;
	int	in_word;
	int	j;

	i = 0;
	in_word = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c && in_word == 0)
		{
			in_word = 1;
			j++;
		}
		else if (str[i] == c)
			in_word = 0;
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		words_count;

	if (!s)
		return (NULL);
	words_count = how_many_words((char *)s, c);
	strings = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!strings)
		return (NULL);
	if (fill_strings(strings, s, c, words_count) != 0)
	{
		free(strings);
		return (NULL);
	}
	return (strings);
}
