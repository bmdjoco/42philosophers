/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:51:49 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/07 00:09:33 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_routine(void *arg)
{
	int		i;
	int		eat;
	t_philo	*philo;

	philo = (t_philo *)arg;
	i = 0;
	eat = 0;
	while (philo->must_eat == -1 || eat < philo->must_eat)
	{
		printf("%u %d is thinking\n", get_time_milisec()
			, philo->num);
		philo->time = get_time_milisec();
		pthread_mutex_lock(philo->l_fork);
		printf("%u %d has taken a fork\n", get_time_milisec()
			, philo->num);
		pthread_mutex_lock(philo->r_fork);
		printf("%u %d has taken a fork\n", get_time_milisec()
			, philo->num);
		printf("%u %d is eating\n", get_time_milisec()
			, philo->num);
		eat++;
		if (get_time_milisec() >= philo->time
			+ philo->time_to_die)
		{
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
			return (printf("%u %d died\n", get_time_milisec()
				, philo->num), NULL);
		}
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		if (get_time_milisec() >= philo->time
			+ philo->time_to_die)
			return (printf("%u %d died\n", get_time_milisec()
				, philo->num), NULL);
		printf("%u %d is sleeping\n", get_time_milisec()
			, philo->num);
		msleep(philo->time_to_sleep);
		i++;
	}
	return (NULL);
}
