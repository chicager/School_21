/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_spec_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 23:18:56 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:19:59 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	manage_spec_d(const char **format, va_list args)
{
	*format += 1;
	s.specifier_d = va_arg(args, int);
	if (s.flag_minus_accuracy == 1)
		s.is_accuracy = 0;
	if (s.specifier_d < 0)
		s.printed_symbols++;
	if (s.width || s.is_accuracy)
	{
		if (s.specifier_d == 0 && s.accuracy == 0 &&
				s.is_accuracy == 1 && s.width > 0)
			s.width++;
		s.width -= get_num_figures(s.specifier_d);
		spec_d_addfn3();
	}
	else
		putnbr_countsym();
}

void	putnbr_countsym(void)
{
	ft_putnbr_fd(s.specifier_d, 1);
	s.printed_symbols += get_num_figures(s.specifier_d);
}

void	spec_d_addfn(void)
{
	if (s.is_accuracy)
	{
		if (s.specifier_d < 0 && s.specifier_d != -2147483648)
		{
			write(1, "-", 1);
			s.specifier_d *= -1;
		}
		while (s.accuracy > get_num_figures(s.specifier_d))
		{
			s.printed_symbols += write(1, "0", 1);
			s.accuracy--;
			s.p_accuracy++;
		}
		if (s.specifier_d != 0 || s.accuracy != 0 || s.is_accuracy != 1)
			putnbr_countsym();
		s.width -= s.p_accuracy;
		ft_putsyms(' ');
	}
	else
	{
		putnbr_countsym();
		ft_putsyms(s.symbol);
	}
}

void	spec_d_addfn2(void)
{
	if (s.specifier_d < 0 && s.width <= 0)
	{
		write(1, "-", 1);
		s.specifier_d *= -1;
	}
	if (s.accuracy > 0)
		s.width = s.width - s.accuracy + get_num_figures(s.specifier_d);
	ft_putsyms(' ');
	if (s.specifier_d < 0)
	{
		write(1, "-", 1);
		s.specifier_d *= -1;
	}
	while (s.accuracy > get_num_figures(s.specifier_d))
	{
		s.printed_symbols += write(1, "0", 1);
		s.accuracy--;
	}
	putnbr_countsym();
}

void	spec_d_addfn3(void)
{
	if (s.specifier_d < 0)
		s.width--;
	if (s.flag_minus)
		spec_d_addfn();
	else
	{
		if (s.is_accuracy && (s.accuracy - get_num_figures(s.specifier_d) > 0))
			spec_d_addfn2();
		else
		{
			if (s.specifier_d < 0 && s.flag_zero &&
				(s.is_accuracy != 1) && s.specifier_d != -2147483648)
			{
				write(1, "-", 1);
				s.specifier_d *= -1;
			}
			if (s.is_accuracy)
				s.symbol = ' ';
			ft_putsyms(s.symbol);
			if (s.specifier_d != 0 || s.accuracy != 0 || s.is_accuracy != 1)
				putnbr_countsym();
		}
	}
}
