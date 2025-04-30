# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 13:05:10 by marcoga2          #+#    #+#              #
#    Updated: 2025/04/22 14:57:18 by marcoga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#newline with \
# compilation variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME = get_next_line.a

# compulsory files
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

# rules
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean re fclean
