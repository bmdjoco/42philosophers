/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:16:00 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/09 12:43:48 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	usage(void)
{
	putstr("Usage : ", 2);
	putstr("number_of_philosophers time_to_die time_to_eat ", 2);
	putstr("time_to_sleep [number_of_times", 2);
	putstr("_each_philosopher_must_eat]\n", 2);
}

void	free_fork(pthread_mutex_t **fork, int i)
{
	i++;
	while (--i >= 0)
	{
		pthread_mutex_destroy(fork[i]);
		free(fork[i]);
	}
	free(fork);
}

int	msleep(long time)
{
	return (usleep(time * 1000));
}

long	get_time_milisec(void)
{
	struct timeval c_time;

	gettimeofday(&c_time, NULL);
	return ((c_time.tv_sec * 1000)
		+ (c_time.tv_usec / 1000));
}
