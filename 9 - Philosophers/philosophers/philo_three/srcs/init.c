/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:34:14 by curreg            #+#    #+#             */
/*   Updated: 2020/12/25 16:35:13 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int				init_data(t_data *data, char **argv)
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
	if (!(data->pids = malloc(sizeof(pid_t) * data->conf.nbr_of_phils)))
		return (1);
	sem_unlink("sem");
	if (!(data->sem = sem_open("sem", O_CREAT,
			S_IRWXU, data->conf.nbr_of_forks)))
		return (1);
	sem_unlink("p_sem");
	if (!(data->p_sem = sem_open("p_sem", O_CREAT, S_IRWXU, 1)))
		return (1);
	data->all_alive = 1;
	return (0);
}

int				create_philos(t_data *data)
{
	int i;

	i = 0;
	if (!(data->philos = malloc(sizeof(t_philo) * (data->conf.nbr_of_phils))))
		return (1);
	while (i < data->conf.nbr_of_phils)
	{
		if (!(data->philos[i] = (t_philo *)malloc(sizeof(t_philo))))
			return (1);
		data->philos[i]->num_of_meals = data->conf.nbr_of_meals;
		data->philos[i]->id = i;
		i++;
	}
	return (0);
}
