/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_symbols.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 22:08:56 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:57:13 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	checking_width_star(const char **format, va_list args)
{
	if (**format == '*')
	{
		s.width = va_arg(args, int);
		if (s.width < 0)
		{
			s.flag_minus = 1;
			s.width *= -1;
			s.symbol = ' ';
			s.flag_zero = 0;
		}
		*format += 1;
	}
}

void	checking_width(const char **format)
{
	if (ft_isdigit(**format))
	{
		s.width = ft_atoi(*format);
		*format += get_num_figures(s.width);
	}
}

void	checking_accuracy(const char **format)
{
	if (**format == '.')
	{
		s.is_accuracy = 1;
		*format += 1;
		s.accuracy = ft_atoi(*format);
		while (**format == '0')
			*format += 1;
		if (ft_isdigit(**format))
			*format += get_num_figures(s.accuracy);
	}
}

void	checking_accuracy_star(const char **format, va_list args)
{
	if (**format == '*')
	{
		s.accuracy = va_arg(args, int);
		if (s.accuracy < 0)
		{
			s.flag_minus_accuracy = 1;
			s.accuracy *= -1;
		}
		*format += 1;
	}
}
