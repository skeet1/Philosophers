/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:13:17 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/22 09:20:30 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_arg(t_data *data, int argc)
{
	if (data->num_philo < 1)
		return (ft_putstr("We need 2 philo at least\n"), 0);
	else if (argc == 6)
	{
		if (data->ntm_eat > 0)
			return(ft_putstr("each philospher must eat one time at least"), 0);
	}
	return (1);
}

long long	ft_atoi(char *s)
{
	long long	i;
	long long	res;
	long long	signe;

	i = 0;
	res = 0;
	signe = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			signe = -1;
		i++;
	}
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = res * 10 + s[i] - 48;
		i++;
	}
	return (res * signe);
}

void	ft_putstr(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}
