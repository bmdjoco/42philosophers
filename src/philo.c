/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:01:27 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/04 17:34:28 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, const char **av)
{
	t_sim	*simu;

	if (!(ac == 5 || ac == 6))
		return (usage(), 1);
	simu = (t_sim *) malloc(sizeof(t_sim));
	(void) av;
	free(simu);
	return (0);
}
