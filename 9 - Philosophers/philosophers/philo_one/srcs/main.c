/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:04:09 by curreg            #+#    #+#             */
/*   Updated: 2020/12/23 22:22:08 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		living(t_data *data, int id, int left_fork, int p_id)
{
	int right_fork;

	right_fork = id;
	pthread_mutex_lock(&data->mutexes[left_fork]);
	pthread_mutex_lock(&data->mutexes[right_fork]);
	print_msg(data, get_time(data), p_id, "has taken a fork");
	print_msg(data, get_time(data), p_id, "is eating");
	gettimeofday(&data->philos[id]->start, NULL);
	usleep_mod(data->conf.time_to_eat);
	pthread_mutex_unlock(&data->mutexes[left_fork]);
	pthread_mutex_unlock(&data->mutexes[right_fork]);
	print_msg(data, get_time(data), p_id, "is sleeping");
	usleep_mod(data->conf.time_to_sleep);
	print_msg(data, get_time(data), p_id, "is thinking");
	if (data->philos[id]->num_of_meals > 0)
		data->philos[id]->num_of_meals -= 1;
}

void		*start_live(void *data)
{
	t_data		*data_ptr;
	int			id;
	int			left_fork;
	int			right_fork;
	int			p_id;

	data_ptr = (t_data *)data;
	id = data_ptr->philo_id;
	p_id = data_ptr->philos[id]->id + 1;
	left_fork = id - 1;
	right_fork = id;
	if (id == 0)
		left_fork = data_ptr->conf.nbr_of_phils - 1;
	while (data_ptr->philos[id]->num_of_meals != 0 && data_ptr->all_live)
		living(data_ptr, id, left_fork, p_id);
	if (data_ptr->philos[id]->num_of_meals == 0)
		data_ptr->philos[id]->is_full = 1;
	return (NULL);
}

void		*observe(void *data)
{
	int		i;
	t_data	*data_ptr;

	data_ptr = (t_data *)data;
	while (1)
	{
		i = 0;
		while (i < data_ptr->conf.nbr_of_phils)
		{
			if (data_ptr->philos[i]->is_full)
			{
				i++;
				continue;
			}
			if (check_death(data_ptr, i))
				return (NULL);
			i++;
			usleep(100);
		}
		if (check_full(data_ptr))
			return (NULL);
	}
	return (NULL);
}

void		stop_all_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->conf.nbr_of_phils)
	{
		pthread_join(data->philos[i]->activity, NULL);
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_data			data;
	pthread_t		observer;

	if (argc < 5 || !check_args(argv))
	{
		write(1, "Error: Invalid input data...\n", 29);
		return (0);
	}
	if (init_data(&data, argv) || create_philos(&data))
	{
		write(1, "Error: Program error...\n", 24);
		return (0);
	}
	gettimeofday(&data.start, NULL);
	philos_get_live(&data);
	pthread_create(&observer, NULL, observe, (void *)&data);
	pthread_join(observer, NULL);
	stop_all_threads(&data);
	return (0);
}
