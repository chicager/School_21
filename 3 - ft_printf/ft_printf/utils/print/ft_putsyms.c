/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsyms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 17:15:01 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:52:21 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putsyms(char symbol)
{
	while (s.width > 0)
	{
		s.printed_symbols += write(1, &symbol, 1);
		s.width--;
	}
}
