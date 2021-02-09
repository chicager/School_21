/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:35:45 by curreg            #+#    #+#             */
/*   Updated: 2020/12/25 16:36:05 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void			print_msg(t_data *data, long int time, int philo_id, char *msg)
{
	char *str_time;
	char *str_philo_id;

	sem_wait(data->p_sem);
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
	if (data->all_alive)
		sem_post(data->p_sem);
}
