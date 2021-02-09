/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:20:50 by curreg            #+#    #+#             */
/*   Updated: 2020/12/23 22:21:09 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		print_msg(t_data *data, long int time, int philo_id, char *msg)
{
	char *str_time;
	char *str_philo_id;

	if (data->all_live || ft_strcmp(msg, "died") == 0)
	{
		pthread_mutex_lock(&data->p_mutex);
		str_time = ft_itoa(time);
		str_philo_id = ft_itoa(philo_id);
		write(1, str_time, ft_strlen(str_time));
		write(1, " ", 1);
		write(1, str_philo_id, ft_strlen(str_philo_id));
		write(1, " ", 1);
		write(1, msg, ft_strlen(msg));
		write(1, "\n", 1);
		free(str_time);
		free(str_philo_id);
		pthread_mutex_unlock(&data->p_mutex);
	}
}
