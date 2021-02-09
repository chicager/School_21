/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:17:49 by curreg            #+#    #+#             */
/*   Updated: 2020/12/25 16:11:24 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_correct_num(char number[])
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

int			check_args(char **argv)
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

int			check_death(t_data *data, int i)
{
	gettimeofday(&data->philos[i]->end, NULL);
	if (get_starving_time(data, i) > data->conf.time_to_die)
	{
		data->all_live = 0;
		print_msg(data, get_time(data),
					data->philos[i]->id + 1, "died");
		return (1);
	}
	return (0);
}

int			check_full(t_data *data)
{
	int i;
	int all_full;

	i = 0;
	all_full = 0;
	while (i < data->conf.nbr_of_phils)
	{
		if (data->philos[i]->is_full)
			all_full++;
		i++;
	}
	if (all_full == data->conf.nbr_of_phils)
		return (1);
	return (0);
}
