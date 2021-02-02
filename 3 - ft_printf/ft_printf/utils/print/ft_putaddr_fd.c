/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:04:35 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:55:45 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	add_code_putaddr(long int div, unsigned long n, char temp, int fd)
{
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
		{
			temp += 39;
			write(fd, &temp, 1);
		}
		else
			write(fd, &temp, 1);
		n %= div;
		div /= 16;
	}
}

void	ft_putaddr_fd(void *str, int fd)
{
	long int			div;
	char				temp;
	unsigned long int	n;

	temp = '0';
	n = (unsigned long int)str;
	div = 16;
	write(fd, "0x", 2);
	if (n < 10)
	{
		temp = '0' + n;
		write(1, &temp, 1);
	}
	else if (n < 16)
	{
		temp = '0' + n;
		temp += 39;
		write(1, &temp, 1);
	}
	else
		add_code_putaddr(div, n, temp, fd);
}
