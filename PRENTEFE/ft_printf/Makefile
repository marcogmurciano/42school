# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marco <marco@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 14:38:44 by marco             #+#    #+#              #
#    Updated: 2025/04/15 16:20:17 by marco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#newline with \
# compilation variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME = libftprintf.a

# compulsory files
SRCS = ft_printf.c number_management.c print_type.c endpoint.c
OBJS = $(SRCS:.c=.o)

# bonus files
# BONUS_SRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
# ft_lstclear_bonus.c ft_lstdelone_bonus.c \
# ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
# ft_lstnew_bonus.c ft_lstsize_bonus.c
# BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# rules
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean re fclean

