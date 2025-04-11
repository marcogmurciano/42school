/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prentef.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:50:15 by marcoga2          #+#    #+#             */
/*   Updated: 2025/04/10 16:06:35 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

int	prentefe(char *format, ...)
{
	int	arg_num;
	int	i;
	char *types_arr;
	int total_memory;
	char *result;

	arg_num = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			arg_num++;
		i++;
	}
	*types_arr = malloc(sizeof(char) * arg_num);
	while(types_arr[i] != NULL)
	{
		//buscar exactamente que letras y que tipo de datos recibe printf
		if (types_arr[i] == long)
			total_memory+=sizeof(long)
		if (types_arr[i] == long)
			total_memory+=sizeof(long)
		if (types_arr[i] == long)
			total_memory+=sizeof(long)
		if (types_arr[i] == long)
			total_memory+=sizeof(long)
		if (types_arr[i] == long)
			total_memory+=sizeof(long)
		if (types_arr[i] == long)
			total_memory+=sizeof(long)
		if (types_arr[i] == long)
			total_memory+=sizeof(long)
		if (types_arr[i] == long)
			total_memory+=sizeof(long)
		if (types_arr[i] == long)
			total_memory+=sizeof(long)
		if (types_arr[i] == long)
			total_memory+=sizeof(long)
		if (types_arr[i] == long)
			total_memory+=sizeof(long)
	}
	total_memory = total_memory + (ft_strlen(format) - (2 * arg_num))
	result = malloc(total_memory * sizeof(char)) //esto chekearlo porque no se yo
}
