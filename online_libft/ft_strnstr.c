/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:59:01 by marco             #+#    #+#             */
/*   Updated: 2025/04/07 15:42:21 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] != '\0' && i + j < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (i + j < len && big[i + j] == little[j] && little[j] != '\0')
				j++;
			if (little[j] == '\0')
				return (((char *)big) + i);
		}
		i++;
	}
	return (NULL);
}
