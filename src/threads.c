/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:44:08 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/08 00:34:24 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	printf("%lu %d has taken a fork\n", get_time_milisec(),
		philo->num);
	pthread_mutex_lock(philo->l_fork);
	printf("%lu %d has taken a fork\n", get_time_milisec(),
		philo->num);
	philo->must_eat = philo->must_eat - 1;
	printf("%lu %d is eating\n", get_time_milisec(),
		philo->num);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->l_fork);
}

static void	philo_sleep(t_philo *philo)
{
	printf("%lu %d is sleeping\n", get_time_milisec(),
		philo->num);
	msleep(philo->time_to_sleep);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->is_dead->mutex);
	if (philo->is_dead->state)
		return (printf("%lu %d is dead\n"
				, get_time_milisec()
				, philo->num)
			, pthread_mutex_unlock(&philo->is_dead->mutex)
			, 1);
	pthread_mutex_unlock(&philo->is_dead->mutex);
	return (0);
}

int	is_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->is_end->mutex);
	if (philo->is_end->state)
		return ( philo->is_end->state = 2
			, pthread_mutex_unlock(&philo->is_end->mutex)
			, 1);
	pthread_mutex_unlock(&philo->is_end->mutex);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (philo->must_eat == -1
		|| philo->must_eat > 1 || !is_dead(philo)
		|| !is_end(philo))
	{
		printf("%lu %d is thinking\n", get_time_milisec()
			, philo->num);
		eat(philo);
		if (is_dead(philo) || is_end(philo))
			return(NULL);
		philo_sleep(philo);
	}
	return (NULL);
}
