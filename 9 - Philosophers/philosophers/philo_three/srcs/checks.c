/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:32:18 by curreg            #+#    #+#             */
/*   Updated: 2020/12/25 16:46:03 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int		is_correct_num(char number[])
{
	int i;

	i = 0;
	if (number[0] == '-')
		return (0);
	while (number[i] != 0)
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int				check_args(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!is_correct_num(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
