/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 13:11:27 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/29 19:53:48 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char		*ft_itoa_negative(char *ptr, int i, int n)
{
	ptr[0] = '-';
	while (n != 0)
	{
		i--;
		ptr[i] = n % 10 * (-1) + '0';
		n = n / 10;
	}
	return (ptr);
}

static char		*ft_itoa_positive(char *ptr, int i, int n)
{
	while (n != 0)
	{
		i--;
		ptr[i] = n % 10 + '0';
		n = n / 10;
	}
	return (ptr);
}

char			*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		m;

	i = 0;
	m = n;
	while (m != 0)
	{
		m = m / 10;
		i++;
	}
	if (n <= 0)
		i++;
	ptr = (char*)malloc(sizeof(char) * i + 1);
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	if (n < 0)
		ptr = ft_itoa_negative(ptr, i, n);
	else if (n == 0)
		ptr[0] = '0';
	else
		ptr = ft_itoa_positive(ptr, i, n);
	return (ptr);
}
