/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_spec_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 23:29:01 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:36:23 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	manage_spec_u(const char **format, va_list args)
{
	*format += 1;
	s.specifier_u = va_arg(args, long long int);
	if (s.width || s.is_accuracy)
	{
		if (s.specifier_u == 0 && s.accuracy == 0 &&
			s.is_accuracy == 1 && s.width > 0)
			s.width++;
		if ((s.accuracy - get_num_figures(s.specifier_u)) > 0)
			s.width = s.width - s.accuracy;
		else
			s.width -= get_num_figures(s.specifier_u);
		if (s.flag_minus)
			spec_u_addfn();
		else
			spec_u_addfn2();
	}
	else
		putuns_countsym();
}

void	putuns_countsym(void)
{
	ft_putuns_fd(s.specifier_u, 1);
	s.printed_symbols += get_num_figures(s.specifier_u);
}

void	spec_u_addfn(void)
{
	if (s.is_accuracy)
	{
		while (s.accuracy > get_num_figures(s.specifier_u))
		{
			s.printed_symbols += write(1, "0", 1);
			s.accuracy--;
			s.p_accuracy++;
		}
		if (s.specifier_u != 0 || s.accuracy != 0 || s.is_accuracy != 1)
			putuns_countsym();
		ft_putsyms(' ');
	}
	else
	{
		putuns_countsym();
		ft_putsyms(s.symbol);
	}
}

void	spec_u_addfn2(void)
{
	if (s.is_accuracy)
	{
		if (s.flag_minus_accuracy == 1)
			ft_putsyms(s.symbol);
		else
			ft_putsyms(' ');
		while (s.accuracy > get_num_figures(s.specifier_u))
		{
			s.printed_symbols += write(1, "0", 1);
			s.accuracy--;
		}
		if (s.specifier_u != 0 || s.accuracy != 0 || s.is_accuracy != 1)
			putuns_countsym();
	}
	else
	{
		ft_putsyms(s.symbol);
		putuns_countsym();
	}
}
