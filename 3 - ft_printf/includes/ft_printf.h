/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:44:40 by curreg            #+#    #+#             */
/*   Updated: 2020/08/03 22:10:38 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

struct	s_variables
{
	int				printed_symbols;
	int				width;
	int				accuracy;
	int				specifier_d;
	char			*specifier_s;
	void			*specifier_p;
	unsigned int	specifier_u;
	unsigned int	specifier_x;
	int				flag_minus;
	int				flag_zero;
	int				flag_minus_accuracy;
	int				is_accuracy;
	int				p_accuracy;
	char			hex_symbol;
	char			symbol;
}					s;

int		ft_printf(const char *format, ...);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		get_num_adr(void *str);
int		get_num_hex(long long int n);
int		get_num_figures(long long int i);
void	add_code_putaddr(long int div, unsigned long n, char temp, int fd);
void	add_code_puthex(long int div, char temp, long long int n, int x);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putuns_fd(long long int n, int fd);
void	ft_putaddr_fd(void *str, int fd);
void	ft_puthex_fd(long long int n, int x);
void	ft_putsyms(char symbol);
void	ft_putsym(const char **format);

void	init(void);
void	checking_space(const char **format);
void	checking_minus(const char **format);
void	checking_zero(const char **format);
void	checking_width_star(const char **format, va_list args);
void	checking_width(const char **format);
void	checking_accuracy(const char **format);
void	checking_accuracy_star(const char **format, va_list args);
void	manage_spec_d(const char **format, va_list args);
void	manage_spec_s(const char **format, va_list args);
void	manage_spec_p(const char **format, va_list args);
void	manage_spec_c(const char **format, va_list args);
void	manage_spec_u(const char **format, va_list args);
void	manage_spec_x(const char **format, va_list args);
void	manage_spec_perc(const char **format);
void	format_parser(const char **format, va_list args);
void	format_processor(const char **format, va_list args);

void	putaddr_countsym(void);
void	putnbr_countsym(void);
void	putuns_countsym(void);
void	puthex_countsym(void);
void	spec_p_addfn(void);
void	spec_p_addfn2(void);
void	spec_d_addfn(void);
void	spec_d_addfn2(void);
void	spec_d_addfn3(void);
void	spec_s_addfn(void);
void	spec_s_addfn2(void);
void	spec_s_addfn3(void);
void	spec_u_addfn(void);
void	spec_u_addfn2(void);
void	spec_u_addfn3(void);
void	spec_x_addfn(void);
void	spec_x_addfn2(void);
void	spec_x_addfn3(void);

#endif
