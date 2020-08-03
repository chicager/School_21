/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_adr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:02:40 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:48:12 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_num_adr(void *str)
{
	long int			div;
	unsigned long int	n;
	int					count;

	count = 2;
	if (str == NULL)
		return (3);
	n = (unsigned long int)str;
	div = 16;
	if (n < 16)
		return (3);
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		n %= div;
		div /= 16;
		count++;
	}
	return (count);
}
