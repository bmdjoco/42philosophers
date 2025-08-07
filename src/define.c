/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:27:24 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/08 00:29:44 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static pthread_mutex_t	*define_fork(int nb)
{
	pthread_mutex_t	*fork;

	fork = malloc(sizeof(pthread_mutex_t) * nb);
	if (!fork)
		return (NULL);
	pthread_mutex_init(fork, NULL);
	return (fork);
}

int	put_value(int ac, const char **av
	, t_philo	*philo, int i)
{
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_die = ft_atoi(av[3]);
	philo->time_to_die = ft_atoi(av[4]);
	philo->num = i;
	if (ac == 6)
		philo->must_eat = ft_atoi(av[5]);
	else
		philo->must_eat = -1;
	if (philo->must_eat < 2)
		return (0);
	return (1);
}

t_philo	*define_table(int ac, const char **av, int nb)
{
	int	i;
	t_philo	*table;

	table = (t_philo *) malloc(sizeof(t_philo) * nb);
	if (!table)
		return (NULL);
	i = -1;
	while (++i < nb)
	{
		if (!put_value(ac, av, &table[i], i))
			return (free(table), NULL);
	}
	return (table);
}

t_sim	*init_simu(int ac, const char **av)
{
	int		i;
	t_sim	*simu;

	simu = malloc(sizeof(t_sim));
	if (!simu)
		return (NULL);
	simu->nb_philo = ft_atoi(av[1]);
	simu->fork = define_fork(simu->nb_philo);
	if (!simu->fork)
		return (free(simu), NULL);
	simu->table = define_table(ac, av, simu->nb_philo);
	if (!simu->table)
		return (free(simu->fork), free(simu), NULL);
	i = -1;
	while (++i < simu->nb_philo)
	{
		simu->table[i].l_fork = &simu->fork[i];
		if (i + 1 == simu->nb_philo)
			simu->table[i].r_fork = &simu->fork[0];
		else
			simu->table[i].r_fork = &simu->fork[i + 1];
	}
	return (simu);
}
