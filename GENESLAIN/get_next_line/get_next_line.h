/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:57:37 by marcoga2          #+#    #+#             */
/*   Updated: 2025/04/23 10:48:14 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// # define BUFFER_SIZE 200

// headers
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>

size_t	linelen_mode(const char *s, int mode);
char	*string_join(char *save, char *temp);
void	*ft_calloc(size_t size, size_t amount);
char	*copy_til_n(char *s);
char	*clear_til_n(char *s);
char	*read_til_n(int fd, char *save);
char	*get_next_line(int fd);

#endif
