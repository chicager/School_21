/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_spec_perc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 23:53:42 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:20:13 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	manage_spec_perc(const char **format)
{
	*format += 1;
	if (s.width)
	{
		s.width--;
		if (s.flag_minus)
		{
			s.printed_symbols += write(1, "%", 1);
			s.symbol = ' ';
			ft_putsyms(s.symbol);
		}
		else
		{
			ft_putsyms(s.symbol);
			s.printed_symbols += write(1, "%", 1);
		}
	}
	else
		s.printed_symbols += write(1, "%", 1);
}
