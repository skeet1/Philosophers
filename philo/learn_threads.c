/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:36:28 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/19 17:54:11 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void*	myturn()
{
	while (1)
	{
		sleep(1);
		printf("MY turn\n");
	}
}

void	yourturn()
{
	while (1)
	{
		sleep(1);
		printf("Your Turn\n");
	}

}

int	main()
{
	pthread_t th;

	pthread_create(&th, NULL, myturn, NULL);
	// myturn();
	yourturn();
}
