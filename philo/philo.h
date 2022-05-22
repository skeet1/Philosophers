/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:14:06 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/22 10:39:07 by mkarim           ###   ########.fr       */
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
}	t_data;


typedef struct s_philo {
	int				index;
	pthread_t		thread;
	int				right_fork;
	int				left_fork;
	int				start;
	int				end;
	int				n_eating;
	pthread_mutex_t		mutex;
}	t_philo;

long long	ft_atoi(char *s);
void		ft_putstr(char *s);
int			ft_check_arg(t_data *data, int argc);

#endif
