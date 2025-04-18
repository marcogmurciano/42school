/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:47:47 by user              #+#    #+#             */
/*   Updated: 2025/04/17 16:49:18 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*s;
// 	unsigned char	*d;
// 	size_t			i;

// 	if (!dest && !src)
// 		return (NULL);
// 	s = (unsigned char *)src;
// 	d = (unsigned char *)dest;
// 	if (d == s || n == 0)
// 		return (dest);
// 	i = -1;
// 	if (s < d)
// 	{
// 		while (n > 0)
// 		{
// 			n--;
// 			d[n] = s[n];
// 		}
// 		n--;
// 		d[n] = s[n];
// 		return (dest);
// 	}
// 	while (++i < n)
// 		d[i] = s[i];
// 	return (dest);
// }
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	if (d == s || n == 0)
		return (dest);
	if (s < d)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
		return (dest);
	}
	i = -1;
	while (++i < n)
		d[i] = s[i];
	return (dest);
}
