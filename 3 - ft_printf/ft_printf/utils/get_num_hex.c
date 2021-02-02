/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:03:08 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:46:41 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_num_hex(long long int n)
{
	long int	div;
	int			count;

	count = 0;
	div = 16;
	if (n < 16)
		return (1);
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
