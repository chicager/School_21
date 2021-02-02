/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:43:44 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 19:01:27 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	format_parser(const char **format, va_list args)
{
	checking_space(format);
	checking_minus(format);
	checking_zero(format);
	checking_width_star(format, args);
	checking_width(format);
	checking_accuracy(format);
	checking_accuracy_star(format, args);
}
