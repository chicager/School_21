/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_only_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:34:47 by curreg            #+#    #+#             */
/*   Updated: 2020/10/16 19:40:29 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

char	*ft_skip_spaces(char *str)
{
	while (*str && *str == ' ')
		str++;
	return (str);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_is_only_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int		ft_is_only_spaces(char *str)
{
	while (*str)
	{
		if (!(*str == ' '))
			return (0);
		str++;
	}
	return (1);
}
