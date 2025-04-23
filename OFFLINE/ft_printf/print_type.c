/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:50:58 by marco             #+#    #+#             */
/*   Updated: 2025/04/15 16:29:45 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printd(int n, int *result)
{
	char	*trans_num;

	numtochar(n, &trans_num, 0);
	if (!trans_num)
		return ;
	print_str(trans_num, result);
	free(trans_num);
}

void	printu(unsigned int n, int *result)
{
	char	*trans_num;

	numtochar(n, &trans_num, 1);
	if (!trans_num)
		return ;
	print_str(trans_num, result);
	free(trans_num);
}

void	printp(void *ptr, int *result)
{
	uintptr_t	addr;

	addr = (uintptr_t)ptr;
	print_str("0x", result);
	put_hex_recursive(addr, result, 0);
}

void	printx(unsigned int n, int *result, int specifier)
{
	int		uppercase;

	uppercase = 0;
	if (specifier == 'X')
		uppercase = 1;
	put_hex_recursive(n, result, uppercase);
}
