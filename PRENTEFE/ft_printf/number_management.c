/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:39:14 by marco             #+#    #+#             */
/*   Updated: 2025/04/15 16:29:23 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	numlen(long n)
{
	int	len;

	len = (n <= 0);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	calculate_len(long n, int is_unsigned)
{
	if (is_unsigned)
		return (numlen((unsigned int)n));
	if (n < 0)
		return (numlen(-n));
	return (numlen(n));
}

void	numtochar(long n, char **result, int is_unsigned)
{
	int				len;
	unsigned long	num;

	len = calculate_len(n, is_unsigned);
	*result = malloc(sizeof(char) * (len + 1));
	if (!(*result))
		return ;
	(*result)[len] = '\0';
	if (!is_unsigned && n < 0)
	{
		(*result)[0] = '-';
		num = -n;
	}
	else
		num = (unsigned long)n;
	while (len-- > 0)
	{
		if (!is_unsigned && n < 0 && len == 0)
			return ;
		(*result)[len] = (num % 10) + '0';
		num /= 10;
	}
}

void	put_hex_recursive(unsigned int n, int *result, int uppercase)
{
	char	*hex_digits;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (n >= 16)
		put_hex_recursive(n / 16, result, uppercase);
	print_char(hex_digits[n % 16], result);
}
