# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: curreg <curreg@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 17:51:43 by curreg            #+#    #+#              #
#    Updated: 2020/12/25 16:38:47 by curreg           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three

SRCS = srcs/utils/ft_atoi.c srcs/utils/ft_isdigit.c \
		srcs/utils/ft_itoa.c srcs/utils/ft_strcmp.c \
		srcs/utils/ft_strlen.c srcs/main.c srcs/checks.c \
		srcs/init.c srcs/print_msg.c srcs/time.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) includes/philo.h
	@gcc $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "[OK] Files .o have been created"
	@echo "[OK] Binary file has been created"

%.o: %.c 
	@gcc -c $(CFLAGS) -o $@ $<

clean:
	@rm -f $(OBJS)
	@echo "[OK] Files .o have been removed"

fclean: clean
	@rm -f $(NAME)
	@echo "[OK] Binary file has been removed"

re: fclean all

.PHONY: all clean fclean re