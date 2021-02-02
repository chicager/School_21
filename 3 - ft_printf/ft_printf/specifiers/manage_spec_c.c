/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_spec_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 23:26:15 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:19:53 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	manage_spec_c(const char **format, va_list args)
{
	*format += 1;
	s.specifier_d = va_arg(args, int);
	if (s.width)
	{
		s.width--;
		if (s.flag_minus)
		{
			s.printed_symbols += write(1, &s.specifier_d, 1);
			ft_putsyms(s.symbol);
		}
		else
		{
			ft_putsyms(s.symbol);
			s.printed_symbols += write(1, &s.specifier_d, 1);
		}
	}
	else
		s.printed_symbols += write(1, &s.specifier_d, 1);
}
