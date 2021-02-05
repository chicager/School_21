/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:17:01 by hmiso             #+#    #+#             */
/*   Updated: 2021/02/05 23:26:43 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdio.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>

# define BUFFER_SIZE 1000
# define PIPE_READ 0
# define PIPE_WRITE 1

int g_error;
int g_signal;

typedef struct	s_vars{
	char			**envp_copy;
	int				count_envp;
	int				save_std_in;
	int				save_std_out;
	int				count_pipe;
	int				count_command;
	int				index_pipe;
	int				count_redirect;
	int				count_call_pipe;
	int				flag_redirect;
	int				err_flag;
	int				err_flag_export;
	int				cd_flag;
	int				*arr_flags;
}				t_vars;

typedef struct	s_upd{

	int				i;
	int				j;
	char			**new_envp;
	char			**ar_1;
	char			**ar_2;
	int				count;
	int				flag;
	char			*ptr;
	char			**new_str;
}				t_upd;

typedef struct	s_space{

	int				i;
	int				flag;
	char			*ptr;
	char			*ptr_for_free;
	char			*line;
}				t_space;

typedef struct	s_sys_func{

	DIR				*dir;
	struct dirent	*st;
	char			**path;
	char			*ptr;
	int				i;
	int				flag;
}				t_sys_func;

typedef struct	s_conveyor{

	char			**line_pipe;
	char			*command_path;
	char			**com_with_flags;
	char			**arr_redirection;
	char			**arr_redirection2;
	int				i;
	int				j;
	int				k;
	int				flag;
	int				flag_pipe;
}				t_conveyor;

typedef struct	s_quotes{

	int				i;
	int				flag;
	int				count;
	char			*line_dubl;
}				t_quotes;

typedef struct	s_envir{

	char			*ptr;
	char			*env_var;
	char			*ptr2;
	char			*ptr_for_free;
	char			*ptr_for_free2;
	int				i;
	int				j;
	int				flag;
	int				k;
}				t_envir;

typedef struct	s_execute{

	char			**command_line;
	char			*command_path;
	char			*ptr_fre;
}				t_execute;

typedef struct	s_parse{

	int				i;
	int				j;
	int				count;
	char			**command_line;
	int				flag;
}				t_parse;

typedef struct	s_unset_vars{

	int				count;
	int				count_env;
	char			**env_new;
	char			**argv;
	int				i;
	int				j;
	int				m;
	int				flag;
}				t_unset_vars;

typedef struct	s_redir{

	pid_t			pid;
	int				status;
	int				fd;
	int				fd2;
	int				count_redirects;
}				t_redir;

typedef struct	s_list_red{

	int				count;
	int				k;
	char			**arr;
}				t_list_red;

typedef struct	s_vt_vars{

	int				i;
	int				j;
	int				fd;
	int				count;
	char			*line;
	char			**new_command_line;
	char			**fre_arr;
	char			**argv;
	char			*fre_ptr;
}				t_vt_vars;

typedef struct	s_move{

	int				i;
	int				poz;
	char			*ptr;
	char			*ptr2;
	int				flag;
	int				flag2;
	int				count;
}				t_move;

typedef struct	s_semic{

	int				i;
	int				flag;
	int				count;
	char			**argv;
	char			*ptr_free;
}				t_semic;

void			update_envp_res(t_upd *upd);
void			fill_new_env(t_upd *upd, char **new_str, int *i, int *m);
void			set_signals(int num);
void			set_g_error(int err);
void			show_g_error();
void			command_error(char *cmd, t_vars *vars);
void			syntax_error(char *cmd);
void			cd_error(char *cmd, char *arg, char *err);
int				check_valid_id(char *str);
void			id_error(char *cmd);
void			set_pwd(char *var, t_vars *vars);
void			envp_copy(char **envp, t_vars *vars);
void			update_envp(char **str, t_vars *vars);
void			export_out(t_vars *vars, char **line);
void			ft_unset(t_vars *vars, char **str);
void			free_two_dimensional_array(char **arr);
void			ft_echo(char **line);
void			ft_echo_n(char **line);
void			ft_env(t_vars *vars);
int				ft_ls(char *line, t_vars *vars);
void			ft_parse_argument(char *line, t_vars *vars);
char			*init_path(t_vars *vars, char *arg);
void			ft_cd(char **command_line, t_vars *vars);
void			ft_pwd(void);
char			**check_duplicate(char **argv);
void			ft_exit(char **command_line);
void			system_func(char *path, char **argv, t_vars *vars);
char			*check_system_func(t_vars *vars, char *str);
void			ft_pipe(char *path, char **command, t_vars *vars);
void			check_pipe(char **command_arr, t_vars *vars);
int				checking_recoded_functions(char **command_line, t_vars *vars);
void			ft_conveyor(char **command_line, t_vars *vars);
void			init_conveyor(t_conveyor *conveyor);
void			conveyor_res(char **command_line, t_vars *vars,
t_conveyor *conveyor);
void			conveyor_res_2(char **command_line, t_vars *vars,
t_conveyor *conveyor);
void			conveyor_res_3(char **command_line, t_vars *vars,
t_conveyor *conveyor);
void			conveyor_res_4(char **command_line, t_vars *vars,
t_conveyor *conveyor);
void			conveyor_res_5(char **command_line, t_vars *vars,
t_conveyor *conveyor);
void			conveyor_res_6(t_vars *vars,
t_conveyor *conveyor);
void			conveyor_res_7(char **command_line, t_vars *vars,
t_conveyor *conveyor);
void			conveyor_res_8(t_conveyor *conveyor);
void			conveyor_res_9(char **command_line, t_vars *vars,
t_conveyor *conveyor);
void			conveyor_res_10(char **command_line, t_vars *vars,
t_conveyor *conveyor);
void			conveyor_res_11(char **command_line, t_vars *vars,
t_conveyor *conveyor);
void			conveyor_res_12(char **command_line, t_vars *vars,
t_conveyor *conveyor);
void			conveyor_res_13(t_vars *vars);
void			check_redirect(char **command_arr, t_vars *vars);
void			quotes_res_4(t_quotes *quotes, char *line);
void			ft_conveyor_test(char *line, char **command_line, t_vars *vars);
void			ft_redirects(char *path, char **command,
char **arr_redirection, t_vars *vars);
void			ft_redirects_revers(t_conveyor *conveyor, t_vars *vars);
char			**move_arguments(char **command_line, t_vars *vars);
void			ft_redirects_pipe(char *path, char **command,
char **arr_redirection, t_vars *vars);
void			ft_redirects_redirect(t_conveyor *conveyor, t_vars *vars);
void			ft_signals(int signal);
void			ft_signal(int signal);
void			ptr_free(char **ptr);
char			**semicolon(char *line);
char			*check_space(char *line_old);
char			*delete_quotes(char *line);
char			**environment_variable_substitution(char **command_line,
t_vars *vars);
void			env_var_res(char **command_line, t_envir *envir);
void			env_var_res_2(char **command_line, t_envir *envir);
void			env_var_res_3(char **command_line, t_envir *envir);
void			env_var_res_4(t_vars *vars, t_envir *envir);
void			env_var_res_5(char **command_line, t_envir *envir);
void			env_var_res_6(char **command_line, t_vars *vars,
													t_envir *envir);
void			env_var_res_7(char **command_line, t_vars *vars,
													t_envir *envir);
char			**count_commands(char *line);
char			**ft_parse(char *line, t_vars *vars);
char			**verification_of_tokens(char **command_line, t_vars *vars);
void			execute_command(char *line, t_vars *vars);
void			create_file(char **command_line, int *arr_flags);
void			ft_pipe_eof(void);
char			*ft_join_path(t_vars *vars, char **com_with_flags);
char			**make_list_redirection_revers(char **command_line,
int i, int j, t_vars *vars);
char			**make_list_redirection(char **command_line,
int i, int j, t_vars *vars);
char			**make_command_arr_start(char **command_line, int i, int j);
void			check_space_res_4(t_space *space);
size_t			ft_strlen(const char *s);
int				get_next_line(int fd, char **line);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t nam, size_t size);
int				ft_check_line(int i, char *line);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
char			*ft_itoa(int n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_sort_str_arr(char **arr);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);

#endif
