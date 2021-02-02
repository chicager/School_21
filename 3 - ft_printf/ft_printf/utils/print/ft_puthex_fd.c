/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:05:55 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:45:52 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	add_code_puthex(long int div, char temp, long long int n, int x)
{
	div = 16;
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
		{
			if (x == 'x')
				temp += 39;
			if (x == 'X')
				temp += 7;
			write(1, &temp, 1);
		}
		else
			write(1, &temp, 1);
		n %= div;
		div /= 16;
	}
}

void	ft_puthex_fd(long long int n, int x)
{
	long int	div;
	char		temp;

	temp = '0';
	div = 0;
	if (n < 10)
	{
		temp = '0' + n;
		write(1, &temp, 1);
	}
	else if (n < 16)
	{
		temp = '0' + n;
		if (x == 'x')
			temp += 39;
		if (x == 'X')
			temp += 7;
		write(1, &temp, 1);
	}
	else
		add_code_puthex(div, temp, n, x);
}
