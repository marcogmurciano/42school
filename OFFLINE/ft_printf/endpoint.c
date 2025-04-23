/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:48:03 by marco             #+#    #+#             */
/*   Updated: 2025/04/15 16:29:50 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, int *result)
{
	write(1, &c, 1);
	(*result)++;
}

void	print_str(const char *s, int *result)
{
	int	i;

	i = -1;
	while (s[++i])
		print_char(s[i], result);
}
