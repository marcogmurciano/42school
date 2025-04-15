/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:24:47 by user              #+#    #+#             */
/*   Updated: 2025/04/15 16:18:21 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// headers
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

// prototypes from all functions
int		numlen(long n);
int		calculate_len(long n, int is_unsigned);
void	numtochar(long n, char **result, int is_unsigned);
void	put_hex_recursive(unsigned int n, int *result, int uppercase);
void	print_char(char c, int *result);
void	print_str(const char *s, int *result);
void	printd(int n, int *result);
void	printu(unsigned int n, int *result);
void	printp(void *ptr, int *result);
void	printx(unsigned int n, int *result, int specifier);
void	read_arg(char specifier, va_list args, int *result, int *reading_arg);
int		ft_printf(const char *format, ...);

#endif
