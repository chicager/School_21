/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:14:37 by curreg            #+#    #+#             */
/*   Updated: 2020/12/23 22:20:02 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int			init_mutex_arr(t_data *data)
{
	int i;

	i = 0;
	if (!(data->mutexes = malloc(sizeof(pthread_mutex_t) *
								data->conf.nbr_of_forks)))
		return (1);
	while (i < data->conf.nbr_of_phils)
	{
		pthread_mutex_init(&data->mutexes[i], NULL);
		i++;
	}
	return (0);
}

int			init_data(t_data *data, char **argv)
{
	memset(data, 0, sizeof(t_data));
	data->conf.nbr_of_phils = ft_atoi(argv[1]);
	data->conf.nbr_of_forks = data->conf.nbr_of_phils;
	data->conf.time_to_die = ft_atoi(argv[2]) * 1000;
	data->conf.time_to_eat = ft_atoi(argv[3]) * 1000;
	data->conf.time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argv[5] == NULL)
		data->conf.nbr_of_meals = -1;
	else
		data->conf.nbr_of_meals = ft_atoi(argv[5]);
	if (init_mutex_arr(data))
		return (1);
	pthread_mutex_init(&data->p_mutex, NULL);
	data->all_live = 1;
	return (0);
}

void		init_philo(t_philo *ph, t_data *data)
{
	ph->activity = NULL;
	ph->num_of_meals = data->conf.nbr_of_meals;
	ph->is_full = 0;
}

int			create_philos(t_data *data)
{
	int i;

	i = 0;
	if (!(data->philos = malloc(sizeof(t_philo) * (data->conf.nbr_of_phils))))
		return (1);
	while (i < data->conf.nbr_of_phils)
	{
		if (!(data->philos[i] = (t_philo *)malloc(sizeof(t_philo))))
			return (1);
		init_philo(data->philos[i], data);
		data->philos[i]->id = i;
		i++;
	}
	return (0);
}

void		philos_get_live(t_data *data)
{
	int i;

	i = 0;
	while (i < data->conf.nbr_of_phils)
	{
		data->philo_id = i;
		pthread_create(&data->philos[i]->activity, NULL,
						start_live, (void *)data);
		gettimeofday(&data->philos[i]->start, NULL);
		usleep(50);
		i++;
	}
}
