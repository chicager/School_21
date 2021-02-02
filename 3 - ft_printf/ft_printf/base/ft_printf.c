/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:10:09 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 17:12:18 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list args;

	s.printed_symbols = 0;
	init();
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format != '\0')
	{
		init();
		if (*format == '%')
		{
			format++;
			format_parser(&format, args);
			format_processor(&format, args);
		}
		else
			ft_putsym(&format);
	}
	va_end(args);
	return (s.printed_symbols);
}
