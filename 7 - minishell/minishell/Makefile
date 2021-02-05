# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 11:46:48 by hmiso             #+#    #+#              #
#    Updated: 2020/11/30 12:28:07 by hmiso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

OBJ_FILES = curreg/check_duplicate.o curreg/check_valid_id.o curreg/envp_copy.o \
curreg/errors.o curreg/export_out.o curreg/fill_new_env.o \
curreg/free_two_dimensional_array.o curreg/ft_cd.o curreg/ft_echo.o \
curreg/ft_echo_n.o curreg/ft_env.o curreg/ft_exit.o curreg/ft_pipe.o \
curreg/ft_pwd.o curreg/ft_unset.o curreg/g_error.o curreg/init_path.o \
curreg/set_pwd.o curreg/set_signals.o curreg/system_func.o curreg/update_envp.o \
curreg/update_envp_res.o \
hmiso/check_pipe.o hmiso/check_redirect.o hmiso/check_space.o hmiso/check_space_res.o \
hmiso/check_system_func.o hmiso/checking_recoded_functions.o hmiso/conveyor.o \
hmiso/conveyor_res.o hmiso/conveyor_res_2.o hmiso/conveyor_res_3.o hmiso/count_commands.o \
hmiso/create_file.o hmiso/delete_quotes.o hmiso/delete_quotes_res.o \
hmiso/environment_variable_substitution.o hmiso/environment_variable_substitution_res.o \
hmiso/execute_command.o hmiso/ft_join_path.o hmiso/ft_parse.o hmiso/ft_parse_argument.o hmiso/ft_pipe_eof.o \
hmiso/ft_redirects.o hmiso/ft_redirects_pipe.o hmiso/ft_redirects_redirect.o \
hmiso/ft_redirects_revers.o hmiso/make_command_arr_start.o hmiso/make_list_redirection.o \
hmiso/make_list_redirection_revers.o hmiso/move_arguments.o hmiso/ptr_free.o hmiso/semicolon.o \
hmiso/verification_of_tokens.o minishell.o \
utils/ft_atoi.o utils/ft_calloc.o utils/ft_check_line.o \
utils/ft_isalpha.o utils/ft_isdigit.o utils/ft_itoa.o \
utils/ft_memset.o utils/ft_putchar_fd.o utils/ft_putendl_fd.o \
utils/ft_putstr_fd.o utils/ft_sort_str_arr.o utils/ft_split.o \
utils/ft_strchr.o utils/ft_strcmp.o utils/ft_strdup.o \
utils/ft_strjoin.o utils/ft_strlcpy.o utils/ft_strlen.o \
utils/ft_strncmp.o utils/ft_substr.o utils/ft_tolower.o \
utils/get_next_line.o \

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILES) minishell.h
	gcc $(FLAG_LINK) $(OBJ_FILES) -o $(NAME)

%.o: %.c 
	gcc -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re