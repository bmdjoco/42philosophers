/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:44:08 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/09 16:15:08 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	iam_dead(t_philo *philo)
{
	if (get_time_milisec() >= philo->time +
		philo->time_to_die)
	{
		pthread_mutex_lock(&philo->is_dead->mutex);
		printf("%lu %d dead\n", get_time_milisec()
			, philo->num);
		philo->is_dead->state = 1;
		pthread_mutex_lock(&philo->is_end->mutex);
		philo->is_end->state = 2;
		pthread_mutex_unlock(&philo->is_end->mutex);
		pthread_mutex_unlock(&philo->is_dead->mutex);
		return (1);
	}
	return (0);
}

static int	eat_bis(t_philo *philo)
{
	if (iam_dead(philo))
		return (1);
	pthread_mutex_lock(philo->r_fork);
	printf("%lu %d has taken a fork\n", get_time_milisec(),
		philo->num);
	if (iam_dead(philo))
		return (pthread_mutex_unlock(philo->r_fork));
	pthread_mutex_lock(philo->l_fork);
	printf("%lu %d has taken a fork\n", get_time_milisec(),
		philo->num);
	if (iam_dead(philo))
		return (pthread_mutex_unlock(philo->r_fork),
				pthread_mutex_unlock(philo->l_fork));
	philo->must_eat = philo->must_eat - 1;
	printf("%lu %d is eating\n", get_time_milisec(),
		philo->num);
	philo->time = get_time_milisec();
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (1);
}

static int	eat(t_philo *philo)
{
	if (philo->num % 2 == 0)
	{
		if (iam_dead(philo))
			return (1);
		pthread_mutex_lock(philo->l_fork);
		printf("%lu %d has taken a fork\n", get_time_milisec(),
			philo->num);
		if (iam_dead(philo))
			return (pthread_mutex_unlock(philo->l_fork));
		pthread_mutex_lock(philo->r_fork);
		printf("%lu %d has taken a fork\n", get_time_milisec(),
			philo->num);
		if (iam_dead(philo))
			return (pthread_mutex_unlock(philo->l_fork),
					pthread_mutex_unlock(philo->r_fork));
		philo->must_eat = philo->must_eat - 1;
		printf("%lu %d is eating\n", get_time_milisec(),
			philo->num);
		philo->time = get_time_milisec();
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	else
		eat_bis(philo);
	return (1);
}

static void	philo_sleep(t_philo *philo)
{
	printf("%lu %d is sleeping\n", get_time_milisec(),
		philo->num);
	msleep(philo->time_to_sleep);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (!is_end(philo))
	{
		philo->time = get_time_milisec();
		printf("%lu %d is thinking\n", get_time_milisec()
			, philo->num);
		eat(philo);
		if (is_end(philo))
			return (NULL);
		philo_sleep(philo);
	}
	return (NULL);
}
