/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_processor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:07:40 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 16:36:04 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	format_processor(const char **format, va_list args)
{
	if (**format == 'd' || **format == 'i')
		manage_spec_d(format, args);
	else if (**format == 's')
		manage_spec_s(format, args);
	else if (**format == 'p')
		manage_spec_p(format, args);
	else if (**format == 'c')
		manage_spec_c(format, args);
	else if (**format == 'u')
		manage_spec_u(format, args);
	else if (**format == 'x' || **format == 'X')
		manage_spec_x(format, args);
	else if (**format == '%')
		manage_spec_perc(format);
}
