# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 16:56:52 by zcherkao          #+#    #+#              #
#    Updated: 2022/07/20 14:23:08 by zcherkao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

SRCS_BONUS = fill_bonus.c \
			init_bonus.c \
			observe_bonus.c \
			operation_bonus.c \
			philo_utils_bonus.c \
			philo_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME): philo_bonus.h $(OBJS_BONUS)
	# @cc -g -fsanitize=thread $(CFLAGS) -o $(NAME) $(OBJS_BONUS)
	@cc $(CFLAGS) -o $(NAME) $(OBJS_BONUS)

%.o: %.c philo_bonus.h
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME)
	
re : fclean all

.PHONY: all clean fclean re