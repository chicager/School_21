/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:04:09 by curreg            #+#    #+#             */
/*   Updated: 2020/12/25 16:36:55 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void			*observe(void *data)
{
	t_data		*data_ptr;
	int			id;

	data_ptr = (t_data *)data;
	id = data_ptr->philo_id;
	while (1)
	{
		gettimeofday(&data_ptr->philos[id]->end, NULL);
		if (get_starving_time(data_ptr, id) > data_ptr->conf.time_to_die)
		{
			data_ptr->all_alive = 0;
			print_msg(data_ptr, get_time(data_ptr),
						data_ptr->philos[id]->id + 1, "died");
			exit(0);
		}
		usleep(10);
	}
	return (NULL);
}

void			start_life(t_data *data)
{
	pthread_t		observer;
	int				id;
	int				p_id;

	id = data->philo_id;
	p_id = data->philos[id]->id + 1;
	gettimeofday(&data->philos[id]->start, NULL);
	pthread_create(&observer, NULL, observe, (void *)data);
	while (data->philos[id]->num_of_meals != 0)
	{
		sem_wait(data->sem);
		sem_wait(data->sem);
		print_msg(data, get_time(data), p_id, "has taken a fork");
		print_msg(data, get_time(data), p_id, "is eating");
		gettimeofday(&data->philos[id]->start, NULL);
		usleep_mod(data->conf.time_to_eat);
		sem_post(data->sem);
		sem_post(data->sem);
		print_msg(data, get_time(data), p_id, "is sleeping");
		usleep_mod(data->conf.time_to_sleep);
		print_msg(data, get_time(data), p_id, "is thinking");
		if (data->philos[id]->num_of_meals > 0)
			data->philos[id]->num_of_meals -= 1;
	}
	exit(1);
}

void			start_processes(t_data *data)
{
	int i;

	i = 0;
	while (i < data->conf.nbr_of_phils)
	{
		data->philo_id = i;
		data->pids[i] = fork();
		if (data->pids[i] < 0)
		{
			write(1, "Error: Process creation error...\n", 33);
			exit(0);
		}
		else if (data->pids[i] == 0)
			start_life(data);
		i++;
		usleep(20);
	}
}

void			wait_processes(t_data *data)
{
	int i;
	int status;
	int eating_philos;

	i = 0;
	status = 0;
	eating_philos = data->conf.nbr_of_phils;
	while (eating_philos > 0)
	{
		waitpid(-1, &status, 0);
		if (status == 0)
		{
			while (i < eating_philos)
			{
				kill(data->pids[i], SIGINT);
				i++;
			}
		}
		else
			eating_philos--;
	}
}

int				main(int argc, char **argv)
{
	t_data data;

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
	start_processes(&data);
	wait_processes(&data);
	sem_close(data.sem);
	sem_close(data.p_sem);
	return (0);
}
