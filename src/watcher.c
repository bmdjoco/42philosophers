/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:59:41 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/08 00:34:55 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	set_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->is_end->mutex);
	philo->is_end->state = 1;
	pthread_mutex_unlock(&philo->is_end->mutex);
}

void	*watcher_routine(void *arg)
{
	int		i;
	int		finish;
	t_sim	*simu;

	simu = (t_sim *)arg;
	finish = 1;
	while (!finish)
	{
		i = -1;
		while (++i < simu->nb_philo && !finish)
			if (is_dead(&simu->table[i])
				|| is_end(&simu->table[i]))
				finish = 0;
	}
	i = -1;
	while (++i < simu->nb_philo)
		set_end(&simu->table[i]);
	return (NULL);
}
