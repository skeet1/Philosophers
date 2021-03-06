/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:14:06 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/13 13:03:44 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				ntm_eat;
	int				death;
	pthread_mutex_t	write;
	pthread_mutex_t	*fork;
	long long		first_time;
}	t_data;

typedef struct s_philo {
	int				index;
	pthread_t		thread;
	int				right_fork;
	int				left_fork;
	int				n_eating;
	long long		last_meal;
	struct s_data	*data;

}	t_philo;

long long	ft_atoi(char *s);
void		ft_putstr(char *s);
int			ft_check_arg(t_data data, int argc);
int			ft_check_num(char **argv, int argc);
int			ft_check(char *str);
void		ft_usleep(long long time, t_data *data);
void		ft_printf(t_data *data, long long time, int id, char *info);
long long	ft_gettime(void);
int			ft_num_eating_check(t_philo *philo, int n_eat,
				int num_philo, int argc);
int			check_death(t_data *data, t_philo *philo, int argc);
void		ft_create_philo(t_philo **ph, t_data *data);
void		ft_init_philo(t_philo **ph, t_data *data);
void		ft_init_data(t_data *data, int argc, char **argv);
void		*routine(void *philo);
#endif
