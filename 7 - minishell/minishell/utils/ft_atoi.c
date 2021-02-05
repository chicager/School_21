/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:29:09 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/29 19:47:29 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_char_int(const char *str, unsigned long m, int c, int i)
{
	int	d;

	d = 0;
	while (ft_isdigit(str[i]))
	{
		m = m * 10 + (str[i] - '0');
		if (str[i] - '0' != 0 || d != 0)
			d++;
		if (d > 19 || m > 9223372036854775807)
		{
			if (c > 0)
				return (-1);
			else
				return (0);
		}
		if (!ft_isdigit(str[i + 1]))
			return ((int)m * c);
		i++;
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	int				i;
	unsigned long	m;
	int				c;

	i = 0;
	m = 0;
	c = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i]
		== '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
		else if (str[i] == '-' && ft_isdigit(str[i + 1]))
		{
			c = -1;
			i++;
		}
		else if (str[i] == '+' && ft_isdigit(str[i + 1]))
			i++;
		else if (ft_isdigit(str[i]))
			return (ft_char_int(str, m, c, i));
		else
			return (0);
	}
	return (0);
}
