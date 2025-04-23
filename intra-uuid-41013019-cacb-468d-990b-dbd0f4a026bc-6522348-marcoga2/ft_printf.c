/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:50:15 by marcoga2          #+#    #+#             */
/*   Updated: 2025/04/21 12:14:11 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	read_arg(char c, va_list args, int *result, int *reading_arg)
{
	*reading_arg = 0;
	if (c == 'c')
	{
		print_char(va_arg(args, int), result);
		result++;
	}
	else if (c == 's')
		print_str(va_arg(args, char *), result);
	else if (c == 'p')
		printp(va_arg(args, void *), result);
	else if (c == 'd' || c == 'i')
		printd(va_arg(args, int), result);
	else if (c == 'u')
		printu(va_arg(args, unsigned int), result);
	else if (c == 'x' || c == 'X')
		printx(va_arg(args, unsigned int), result, c);
	else if (c == '%')
		print_char('%', result);
	else
		return ;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;
	int		i;
	int		reading_arg;

	reading_arg = 0;
	result = 0;
	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%' || reading_arg)
		{
			if (reading_arg)
				read_arg(format[i], args, &result, &reading_arg);
			else
				reading_arg = 1;
		}
		else
			print_char(format[i], &result);
	}
	va_end(args);
	return (result);
}
