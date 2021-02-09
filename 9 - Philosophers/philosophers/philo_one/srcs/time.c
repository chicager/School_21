/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:10:10 by curreg            #+#    #+#             */
/*   Updated: 2020/12/25 16:58:39 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static uint32_t	time_now(void)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000000 + t.tv_usec);
}

static long int	timedifference_msec(t_data *data)
{
	return (((data->end.tv_sec * 1000000 + data->end.tv_usec) -
			(data->start.tv_sec * 1000000 + data->start.tv_usec)) / 1000);
}

long int		get_time(t_data *data)
{
	gettimeofday(&data->end, NULL);
	return (timedifference_msec(data));
}

void			usleep_mod(unsigned int ms)
{
	unsigned const end = time_now() + ms;

	while (time_now() < end)
		usleep(50);
}

long int		get_starving_time(t_data *data, int i)
{
	return ((data->philos[i]->end.tv_sec * 1000000 +
			data->philos[i]->end.tv_usec) -
			(data->philos[i]->start.tv_sec * 1000000 +
			data->philos[i]->start.tv_usec));
}
