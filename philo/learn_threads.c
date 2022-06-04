/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:36:28 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/27 18:16:20 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void*	myturn()
// {
// 	int i = 8;
// 	while (i--)
// 	{
// 		sleep(1);
// 		printf("MY turn\n");
// 	}
// 	return ("Hello from My Turn you're going goood \n");
// }

// void	yourturn()
// {
// 	int i = 5;
// 	while (i--)
// 	{
// 		sleep(1);
// 		printf("Your Turn\n");
// 	}
// }

// int	main()
// {
// 	pthread_t th;
// 	char	*str;

// 	pthread_create(&th, NULL, myturn, NULL);
// 	// myturn();
// 	yourturn();
// 	pthread_join(th, (void *)&str);
// 	// pthread_detach(th);
// 	printf("%s", str);
// }

int 	mails = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void	*routine()
{
	for (int i = 0; i < 1000000; i++)
	{
		// pthread_mutex_lock(&lock);
		mails++;
		// pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

int main()
{
	pthread_t t, t1;
	// pthread_create(&t1, NULL, routine, NULL);
	pthread_create(&t, NULL, routine, NULL);
	routine();
	pthread_join(t, NULL);
	// pthread_join(t1, NULL);
	printf("%d\n", mails);
}
