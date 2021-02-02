/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:12:23 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:53:31 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init(void)
{
	s.symbol = ' ';
	s.flag_minus = 0;
	s.flag_zero = 0;
	s.accuracy = 0;
	s.p_accuracy = 0;
	s.is_accuracy = 0;
	s.width = 0;
	s.specifier_d = 0;
	s.specifier_s = NULL;
	s.specifier_p = NULL;
	s.specifier_u = 0;
	s.specifier_x = 0;
	s.hex_symbol = 'x';
	s.flag_minus_accuracy = 0;
}
