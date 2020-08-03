/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_figures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:00:59 by curreg            #+#    #+#             */
/*   Updated: 2020/08/02 18:56:12 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_num_figures(long long int i)
{
	int	count;

	count = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		i = i * -1;
	while (i > 0)
	{
		count++;
		i = i / 10;
	}
	return (count);
}
