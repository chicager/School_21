/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 20:02:33 by curreg            #+#    #+#             */
/*   Updated: 2020/12/25 16:41:13 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct			s_config{
	int					nbr_of_phils;
	int					nbr_of_forks;
	int					nbr_of_meals;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
}						t_config;

typedef struct			s_philo{
	int					id;
	struct timeval		start;
	struct timeval		end;
	int					num_of_meals;
}						t_philo;

typedef struct			s_data{
	t_philo				**philos;
	t_philo				philo;
	t_config			conf;
	struct timeval		start;
	struct timeval		end;
	int					philo_id;
	int					all_alive;
	sem_t				*sem;
	sem_t				*p_sem;
	pid_t				*pids;
}						t_data;

int						ft_atoi(const char *str);
size_t					ft_strlen(const char *s);
char					*ft_itoa(long int n);
int						ft_isdigit(int c);
int						ft_strcmp(char *s1, char *s2);
int						check_args(char **argv);
int						create_philos(t_data *data);
int						init_data(t_data *data, char **argv);
void					usleep_mod(unsigned int ms);
long int				get_time(t_data *data);
long int				get_starving_time(t_data *data, int i);
void					print_msg(t_data *data, long int time,
									int philo_id, char *msg);

#endif
