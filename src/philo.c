/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:17:09 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/09 15:07:19 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_t	*get_thread(int ac, const char **av)
{
	int			nb;
	pthread_t	*thread;

	if (!(ac == 5 || ac == 6))
		return (usage(), NULL);
	nb = ft_atoi(av[1]);
	if (nb < 2)
		return (printf("You need more than 1 philosophers\n"),
			usage(), NULL);
	thread = (pthread_t *) malloc(sizeof(pthread_t) * nb);
	if (!thread)
		return (printf("=1\n"), NULL);
	return (thread);
}

int	main(int ac, const char **av)
{
	int			i;
	int			nb;
	pthread_t	*thread;
	t_sim		*simu;

	thread = get_thread(ac, av);
	if (!thread)
		return (1);
	i = -1;
	simu = init_simu(ac, av);
	if (!simu)
		return (free(thread), 1);
	nb = ft_atoi(av[1]);
	while (++i < nb)
		pthread_create(&thread[i], NULL, philo_routine, simu->table[i]);
	i = -1;
	while (++i < nb)
		pthread_join(thread[i], NULL);
	free_simu(simu);
	free(thread);
	return (0);
}
