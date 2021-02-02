/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 21:38:58 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 16:23:31 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	checking_space(const char **format)
{
	if (**format == ' ')
	{
		s.printed_symbols += write(1, " ", 1);
		*format += 1;
	}
}

void	checking_minus(const char **format)
{
	if (**format == '-')
	{
		s.flag_minus = 1;
		*format += 1;
		while ((**format == '-' || **format == '0') && **format != '\0')
			*format += 1;
	}
}

void	checking_zero(const char **format)
{
	if (**format == '0')
	{
		if (!s.flag_minus)
		{
			s.flag_zero = 1;
			s.symbol = '0';
			while (**format == '0')
				*format += 1;
			if (**format == '-')
			{
				s.flag_zero = 0;
				s.symbol = '0';
				*format += 1;
				s.flag_minus = 1;
				while ((**format == '-' || **format == '0') && **format != '\0')
					*format += 1;
				;
			}
		}
		else
			*format += 1;
		;
	}
}
