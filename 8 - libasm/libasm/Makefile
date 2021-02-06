# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: curreg <curreg@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 17:59:03 by curreg            #+#    #+#              #
#    Updated: 2020/11/01 14:02:39 by curreg           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
NAME_BONUS = libasm_bonus.a
NFLAGS = -f macho64
CFLAGS = -Wall -Wextra -Werror
TEST_RES = tests/test_results

SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s	\
		ft_read.s	\
		ft_strdup.s

B_SRCS = ft_list_size_bonus.s \
		ft_list_push_front_bonus.s 

OBJS = $(SRCS:.s=.o)
B_OBJS = $(B_SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo ["OK] Files .o have been created"
	@ar rc $(NAME) $(OBJS) $^
	@echo ["OK] Library for libasm has been created"
	@ranlib $(NAME)
	@echo "[OK] Index for libasm has been generated"

$(NAME_BONUS): $(B_OBJS)
	@echo ["OK] Files .o have been created"
	@ar rc $(NAME_BONUS) $(B_OBJS) $^
	@echo ["OK] Library for libasm_bonus has been created"
	@ranlib $(NAME_BONUS)
	@echo "[OK] Index for libasm_bonus has been generated"

%.o: %.s 
	@nasm -s $(NFLAGS) -o $@ $<

clean:
	@rm -f $(OBJS) $(B_OBJS)
	@echo "[OK] Files .o have been removed"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS) $(TEST_RES) tests/text.txt tests/ft_text.txt
	@echo "[OK] All files have been removed"

re: fclean all

bonus: $(NAME_BONUS)

test: $(NAME) clean
	@echo ["OK] Creating test files..."
	@gcc $(CFLAGS) -L. -lasm -o $(TEST_RES) tests/main.c
	@echo ["OK] Launching tests..."
	@./$(TEST_RES) < Makefile

btest: $(NAME_BONUS) clean
	@echo ["OK] Creating test files..."
	@gcc $(CFLAGS) $(NAME_BONUS) -o $(TEST_RES) tests/main_bonus.c
	@echo ["OK] Launching tests..."
	@./$(TEST_RES) < Makefile

.PHONY:	all clean fclean re bonus test btest