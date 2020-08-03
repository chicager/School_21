/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_spec_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 23:20:24 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:20:18 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	manage_spec_s(const char **format, va_list args)
{
	*format += 1;
	s.specifier_s = va_arg(args, char *);
	if (s.specifier_s == NULL)
		s.specifier_s = "(null)";
	if (s.flag_minus_accuracy == 1)
		s.is_accuracy = 0;
	if (s.width || s.is_accuracy)
		spec_s_addfn();
	else
	{
		if (s.specifier_s != NULL)
		{
			ft_putstr_fd(s.specifier_s, 1);
			s.printed_symbols += ft_strlen(s.specifier_s);
		}
		else
		{
			ft_putstr_fd("(null)", 1);
			s.printed_symbols += ft_strlen("(null)");
		}
	}
}

void	spec_s_addfn(void)
{
	s.width -= ft_strlen(s.specifier_s);
	if (s.flag_minus)
	{
		if (s.is_accuracy)
			spec_s_addfn2();
		else
		{
			ft_putstr_fd(s.specifier_s, 1);
			s.printed_symbols += ft_strlen(s.specifier_s);
			ft_putsyms(s.symbol);
		}
	}
	else
	{
		if (s.is_accuracy)
			spec_s_addfn3();
		else
		{
			ft_putsyms(s.symbol);
			ft_putstr_fd(s.specifier_s, 1);
			s.printed_symbols += ft_strlen(s.specifier_s);
		}
	}
}

void	spec_s_addfn2(void)
{
	if (s.accuracy == 0)
		s.width += ft_strlen(s.specifier_s);
	if (s.accuracy > 0 && (s.accuracy < ft_strlen(s.specifier_s)))
		s.width = s.width - s.accuracy + ft_strlen(s.specifier_s);
	while (s.accuracy > ft_strlen(s.specifier_s))
		s.accuracy--;
	if (s.accuracy > 0)
	{
		while (s.accuracy > 0)
		{
			s.printed_symbols += write(1, s.specifier_s++, 1);
			s.accuracy--;
		}
	}
	ft_putsyms(' ');
}

void	spec_s_addfn3(void)
{
	if (s.accuracy == 0)
		s.width += ft_strlen(s.specifier_s);
	if (s.accuracy > 0 && (s.accuracy < ft_strlen(s.specifier_s)))
		s.width = s.width - s.accuracy + ft_strlen(s.specifier_s);
	ft_putsyms(' ');
	while (s.accuracy > ft_strlen(s.specifier_s))
		s.accuracy--;
	if (s.accuracy > 0)
	{
		while (s.accuracy > 0)
		{
			s.printed_symbols += write(1, s.specifier_s++, 1);
			s.accuracy--;
		}
	}
}
