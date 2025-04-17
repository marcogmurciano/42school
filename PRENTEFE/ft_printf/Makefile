# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 14:38:44 by marco             #+#    #+#              #
#    Updated: 2025/04/17 13:05:29 by marcoga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#newline with \
# compilation variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft/
AR = ar rcs
NAME = libftprintf.a

# compulsory files
SRCS = ft_printf.c number_management.c print_type.c endpoint.c
OBJS = $(SRCS:.c=.o)


# rules
all: $(NAME)

libft: libft/libft.a
	make -C libft
#    LIBDIR_PATH
# -L libft -lft
$(NAME): $(OBJS) libft
	$(AR) $(NAME) $(OBJS) libft/libft.a

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean re fclean

