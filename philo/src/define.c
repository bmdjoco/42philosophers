/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:31:33 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/07 00:17:34 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*define_philo(const char **av, int ac, int *fork)
{
	int	i;
	int	nb_philo;
	t_philo *philo;

	nb_philo = ft_atoi(av[1]);
	if (nb_philo == 0)
		return (NULL);
	philo = (t_philo *) malloc(sizeof(t_philo) * nb_philo);
	if (!philo)
		return (NULL);
	i = -1;
	while (++i < nb_philo)
	{
		philo->time_to_die = ft_atoi(av[2]);
		philo->time_to_die = ft_atoi(av[3]);
		philo->time_to_die = ft_atoi(av[4]);
		philo->num = i;
		if (ac == 6)
			philo->must_eat = ft_atoi(av[5]);
		else
			philo->must_eat = -1;
		philo->l_fork = &fork[i];
		if (i + 1 == nb_philo)
			philo->r_fork = &fork[0];
		else
			philo->r_fork = &fork[i + 1];
	}
	return (philo);
}

static pthread_mutex_t	*define_fork(int nb)
{
	pthread_mutex_t	*fork;

	fork = malloc(sizeof(pthread_mutex_t) * nb);
	if (!fork)
		return (NULL);
	pthread_mutex_init(fork, NULL);
	return (fork);
}

static void	define_fork(pthread_mutex_t **fork, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		pthread_mutex_destroy(fork[i]);
		free(fork[i]);
	}
}

t_sim	*define_sim(const char **av, int ac)
{
	t_sim	*simu;

	simu = (t_sim *) malloc(sizeof(t_sim));
	if (!simu)
		return (NULL);
	simu->nb_philo = ft_atoi(av[1]);
	if (simu->nb_philo == 0)
		return (free(simu), NULL);
	simu->fork = define_fork(simu->nb_philo);
	if (!simu->fork)
		return (free(simu), NULL);
	simu->philo = define_philo(av, ac, simu->fork);
	if (!simu->philo)
		return (free(simu->fork), free(simu), NULL);
	return (simu);
}
