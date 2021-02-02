/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_spec_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 23:49:05 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:36:43 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	manage_spec_x(const char **format, va_list args)
{
	if (**format == 'X')
		s.hex_symbol = 'X';
	*format += 1;
	s.specifier_x = va_arg(args, unsigned int);
	if (s.width || s.is_accuracy)
		spec_x_addfn3();
	else
		puthex_countsym();
}

void	puthex_countsym(void)
{
	ft_puthex_fd(s.specifier_x, s.hex_symbol);
	s.printed_symbols += get_num_hex(s.specifier_x);
}

void	spec_x_addfn(void)
{
	if (s.is_accuracy)
	{
		while (s.accuracy > get_num_hex(s.specifier_x))
		{
			s.printed_symbols += write(1, "0", 1);
			s.accuracy--;
			s.p_accuracy++;
		}
		if (s.specifier_x != 0 || s.accuracy != 0 || s.is_accuracy != 1)
			puthex_countsym();
		s.width -= s.p_accuracy;
		ft_putsyms(' ');
	}
	else
	{
		puthex_countsym();
		ft_putsyms(s.symbol);
	}
}

void	spec_x_addfn2(void)
{
	if ((s.accuracy - get_num_hex(s.specifier_x)) > 0)
		s.width = s.width - s.accuracy + get_num_hex(s.specifier_x);
	if (s.flag_minus_accuracy == 1)
		ft_putsyms(s.symbol);
	else
		while (s.width > 0)
		{
			s.printed_symbols += write(1, " ", 1);
			s.width--;
		}
	while (s.accuracy > get_num_hex(s.specifier_x))
	{
		s.printed_symbols += write(1, "0", 1);
		s.accuracy--;
	}
	if (s.specifier_x != 0 || s.accuracy != 0 || s.is_accuracy != 1)
		puthex_countsym();
}

void	spec_x_addfn3(void)
{
	if (s.specifier_x == 0 && s.accuracy == 0 &&
		s.is_accuracy == 1 && s.width > 0)
		s.width++;
	s.width -= get_num_hex(s.specifier_x);
	if (s.flag_minus)
		spec_x_addfn();
	else
	{
		if (s.is_accuracy)
			spec_x_addfn2();
		else
		{
			ft_putsyms(s.symbol);
			puthex_countsym();
		}
	}
}
