/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 18:38:46 by curreg            #+#    #+#             */
/*   Updated: 2020/12/16 18:38:35 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int		ft_get_value(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static int		ft_get_len(int num)
{
	int len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char			*ft_itoa(long int n)
{
	char	*dest;
	int		len;

	len = ft_get_len(n);
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len] = '\0';
	if (n < 0)
		dest[0] = '-';
	else if (n == 0)
		dest[0] = '0';
	while (n != 0)
	{
		len--;
		dest[len] = ft_get_value(n % 10) + '0';
		n /= 10;
	}
	return (dest);
}
