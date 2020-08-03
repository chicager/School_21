/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 19:47:34 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:52:06 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char ch;

	ch = (unsigned char)c;
	write(fd, &ch, 1);
}
