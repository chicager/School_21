# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/18 20:15:21 by hmiso             #+#    #+#              #
#    Updated: 2020/08/02 18:19:36 by curreg           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = base/ft_printf.c \
	utils/aux/ft_atoi.c utils/aux/ft_isdigit.c utils/aux/ft_strlen.c utils/print/ft_putaddr_fd.c \
	utils/print/ft_putchar_fd.c utils/print/ft_puthex_fd.c utils/print/ft_putnbr_fd.c \
	utils/print/ft_putstr_fd.c utils/print/ft_putsym.c utils/print/ft_putsyms.c utils/print/ft_putuns_fd.c \
	utils/get_num_adr.c utils/get_num_figures.c utils/get_num_hex.c \
	utils/init.c utils/checking_flags.c utils/checking_symbols.c \
	specifiers/manage_spec_d.c specifiers/manage_spec_s.c \
	specifiers/manage_spec_p.c specifiers/manage_spec_c.c \
	specifiers/manage_spec_u.c specifiers/manage_spec_x.c \
	specifiers/manage_spec_perc.c parser/format_parser.c \
	processor/format_processor.c

OBJ = base/ft_printf.o \
	utils/aux/ft_atoi.o utils/aux/ft_isdigit.o utils/aux/ft_strlen.o utils/print/ft_putaddr_fd.o \
	utils/print/ft_putchar_fd.o utils/print/ft_puthex_fd.o utils/print/ft_putnbr_fd.o \
	utils/print/ft_putstr_fd.o utils/print/ft_putsym.o utils/print/ft_putsyms.o utils/print/ft_putuns_fd.o \
	utils/get_num_adr.o utils/get_num_figures.o utils/get_num_hex.o \
	utils/init.o utils/checking_flags.o utils/checking_symbols.o \
	specifiers/manage_spec_d.o specifiers/manage_spec_s.o \
	specifiers/manage_spec_p.o specifiers/manage_spec_c.o \
	specifiers/manage_spec_u.o specifiers/manage_spec_x.o \
	specifiers/manage_spec_perc.o parser/format_parser.o \
	processor/format_processor.o

COMPILE = gcc -c -Wall -Wextra -Werror
RM = rm -f

INCLUDES = ./includes/*.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	@echo ["OK] Files .o has been created"
	@ar rc $(NAME) $(OBJ) $^
	@echo "[OK] Library for printf has been created"
	@ranlib $(NAME)
	@echo "[OK] Index for printf has been generated"
	
%.o: %.c $(INCLUDES)
	@$(COMPILE) $< -o $@
	
clean:
	@$(RM) $(OBJ)
	@echo "[OK] Files .o has been removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "[OK] File libftprintf.a has been removed"

re: fclean all