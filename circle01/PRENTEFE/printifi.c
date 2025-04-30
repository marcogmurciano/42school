/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printifi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:50:15 by marcoga2          #+#    #+#             */
/*   Updated: 2025/04/14 16:54:25 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <libft.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

/////////////////////////
//////itoa//////////////
////////////////////

#include <stdlib.h>

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
////////////////////////////////////

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

void	ft_itoa(long n, char **result, int is_unsigned)
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
	char *hex_digits;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";

	if (n >= 16)
		put_hex_recursive(n / 16, result, uppercase);
	print_char(hex_digits[n % 16], result);
}

/////////////////////////////////////////


void	printd(int n, int *result)
{
	char	*trans_num;

	ft_itoa(n, &trans_num, 0);
	if (!trans_num)
		return ;
	print_str(trans_num, result);
	free(trans_num);
}

void	printu(unsigned int n, int *result)
{
	char	*trans_num;

	ft_itoa(n, &trans_num, 1);
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
	char	*trans_num;
	int		uppercase;

	uppercase = 0;
	if (specifier == 'X')
		uppercase = 1;
	put_hex_recursive(n, result, uppercase);
}

///////////////////////////////////////////////////

void	read_arg(char specifier, va_list args, int *result, int *reading_arg)
{
	*reading_arg = 0;
	if (specifier == 'c')
	{
		print_char(va_arg(args, int), result);
		result++;
	}
	else if (specifier == 's')
		print_str(va_arg(args, char *), result);
	else if (specifier == 'p')
		printp(va_arg(args, void *), result);
	else if (specifier == 'd' || specifier == 'i')
		printd(va_arg(args, int), result);
	else if (specifier == 'u')
		printu(va_arg(args, unsigned int), result);
	else if (specifier == 'x' || specifier == 'X')
		printx(va_arg(args, unsigned int), result, specifier);
	else if (specifier == '%')
		print_char('%', result);
	else
		return ;
}

int	my_own_printf(const char *format, ...)
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
//////////////////////////////////
/////////////pruebas//////////////
//////////////////////////////////

int	main(void)
{
	void *hola;
	void *hol;
	void *ho;
	void *h;
	my_own_printf("hola %p \n hol %p \n ho %p \n h %p \n", hola, hol, ho, h);
}
