/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:32:28 by user              #+#    #+#             */
/*   Updated: 2025/04/07 15:43:36 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*pointer;

	pointer = malloc(size * number);
	if (pointer == NULL)
		return (NULL);
	ft_memset(pointer, 0, number * size);
	return (pointer);
}
