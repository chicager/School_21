/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 04:02:52 by curreg            #+#    #+#             */
/*   Updated: 2021/02/13 04:15:59 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_int_length(int num)
{
	int length;

	length = 0;
	if (!num)
		return (0);
	while (num)
	{
		num /= 10;
		length++;
	}
	return (length);
}
