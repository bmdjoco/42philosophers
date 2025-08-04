/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:31:33 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/05 01:17:23 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	define_philo(char **av, t_philo *philo, int *fork)
{
	int	i;
	int	nb_philo;

	nb_philo = ft_atoi(av[1]);
	if (nb_philo == 0)
		return (0);
	philo = (t_sim *) malloc(sizeof(t_sim) * nb_philo);
	i = 0;
	while (i < nb_philo)
	{
		philo->time_to_die = ft_atoi(av[2]);
		philo->time_to_die = ft_atoi(av[3]);
		philo->time_to_die = ft_atoi(av[4]);
		if(av[5])
			philo->must_eat = ft_atoi(av[5]);
		//check philo
		philo->l_fork = &fork[i];
		if (i + 1 == nb_philo)
			philo->r_fork = &fork[0];
		else
			philo->r_fork = &fork[i + 1];
		i++;
	}
	return (1);
}
