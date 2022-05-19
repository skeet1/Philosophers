/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:14:06 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/19 15:04:28 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef	struct	s_philo {
	int	num_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nt_eat;
}			t_philo;

long long	ft_atoi(char *s);
void	ft_putstr(char *s);

#endif
