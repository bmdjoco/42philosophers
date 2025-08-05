/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:01:27 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/05 12:07:11 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, const char **av)
{
	t_sim	*simu;

	if (!(ac == 5 || ac == 6))
		return (usage(), 1);
	simu = define_sim(av, ac);
	if(!simu)
		return (1);
	put_philo(simu);
	return (free(simu->fork), free(simu->philo),
		free(simu), 0);
}
