# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 17:41:39 by zcherkao          #+#    #+#              #
#    Updated: 2022/07/19 15:33:54 by zcherkao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

SRCS = operation.c \
		fill.c \
		init.c \
		philo_utils.c \
		philo.c \
		observe.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): philo.h $(OBJS)
	@cc $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)
	
re : fclean all

.PHONY: all clean fclean re