/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:49:42 by user              #+#    #+#             */
/*   Updated: 2025/04/07 16:48:09 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;
	size_t	overflow_checker;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	overflow_checker = dst_len;
	if (size > dst_len)
	{
		while (overflow_checker + i < size - 1 && src[i] != '\0')
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	else
		return (src_len + size);
	return (src_len + dst_len);
}
