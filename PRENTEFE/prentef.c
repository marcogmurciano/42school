/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prentef.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:50:15 by marcoga2          #+#    #+#             */
/*   Updated: 2025/04/11 15:30:06 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <libft.h>
#include <stdarg.h>

int	check_percent(int *i, int *array_num, char **format, char **types_arr)
{
	int	arg_num;

	arg_num = 0;
	if (format[*i] != '%')
	{
		arg_num++;
		if (types_arr)
		{
			types_arr[array_num] = format[i];
			array_num++;
		}
	}
	return (arg_num)
}

int	count_args(char *types, char *format)
{
	int	arg_num;
	int	reading_arg;
	int	i;
	int	array_n;

	reading_arg = 0;
	arg_num = 0;
	arr_num = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' || reading_arg)
		{
			if (!reading_arg)
				reading_arg = 1;
			else
			{
				reading_arg = 0;
				arg_num = arg_num + check_percent(&i, &arr_n, &format, &types);
			}
		}
	}
	return (arg_num);
}

// int	prentefe(char *format, ...)
// {
// 	*types_arr = malloc(sizeof(char) * arg_num);
// 	i = 0;
// 	while (types_arr[i] != NULL)
// 	{
// 		// buscar exactamente que letras y que tipo de datos recibe printf
// 		// • %c Imprime un solo carácter.
// 		// • %s Imprime una string (como se define por defecto en C).
// 		// • %p El puntero void
// 		*dado como argumento se imprime en formato hexadecimal.
// 			// • %d Imprime un número decimal (base 10).
// 			// • %i Imprime un entero en base 10.
// 			// • %u Imprime un número decimal (base 10) sin signo.
// 			// • %x Imprime un número hexadecimal (base 16) en minúsculas.
// 			// • %X Imprime un número hexadecimal (base 16) en mayúsculas.
// 			// • %% para imprimir el símbolo del porcentaje
// 			if (types_arr[i] == long) total_memory += sizeof(long) i++;
// 	}
// 	total_memory = total_memory + ((ft_strlen(format) - (2 * arg_num))
// 			* sizeof(char)) result = malloc(total_memory)
// 	// esto chekearlo porque no se yo
// }

int main(void)
{
	char	*types;
	char	*format;
	int		arg_num;

	format = "hey que pasa%";
	arg_num = count_args(types, format);
	*types_arr = malloc(sizeof(char) * arg_num);
	count_args(types, format);

	return (0);
}
