/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_spec_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 23:22:15 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:20:04 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	manage_spec_p(const char **format, va_list args)
{
	*format += 1;
	s.specifier_p = va_arg(args, void *);
	if (s.width)
	{
		if (s.accuracy == 0 && s.is_accuracy == 1)
			spec_p_addfn();
		else
			spec_p_addfn2();
	}
	else
	{
		if (s.accuracy == 0 && s.is_accuracy == 1)
			s.printed_symbols += write(1, "0x", 2);
		else
			putaddr_countsym();
	}
}

void	putaddr_countsym(void)
{
	ft_putaddr_fd(s.specifier_p, 1);
	s.printed_symbols += get_num_adr(s.specifier_p);
}

void	spec_p_addfn(void)
{
	s.width -= 2;
	if (s.flag_minus)
	{
		s.printed_symbols += write(1, "0x", 2);
		ft_putsyms(s.symbol);
	}
	else
	{
		ft_putsyms(s.symbol);
		s.printed_symbols += write(1, "0x", 2);
	}
}

void	spec_p_addfn2(void)
{
	s.width -= get_num_adr(s.specifier_p);
	if (s.flag_minus)
	{
		putaddr_countsym();
		ft_putsyms(s.symbol);
	}
	else
	{
		ft_putsyms(s.symbol);
		putaddr_countsym();
	}
}
