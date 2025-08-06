/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:16:00 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/06 21:50:07 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	usage(void)
{
	putstr("Usage : ", 2);
	putstr("number_of_philosophers time_to_die time_to_eat ", 2);
	putstr("time_to_sleep [number_of_times", 2);
	putstr("_each_philosopher_must_eat]\n", 2);
}

int	msleep(unsigned int time)
{
	return (usleep(time * 1000));
}

long	get_time_milisec(void)
{
	struct timeval c_time;

	gettimeofday(&c_time, NULL);
	return ((c_time.tv_sec * 1000)
		+ (c_time.tv_usec / 1000));
}

/*tmp*/
void put_philo(t_sim *simu)
{
	printf("Philosophers:\n");
	printf("Nomber of philosophers | %d\n", simu->nb_philo);
	printf("time to eat | %d\n", simu->philo->time_to_eat);
	printf("ime_to_sleep | %d\n", simu->philo->time_to_sleep);
	printf("time_to_eat | %d\n", simu->philo->time_to_die);
	printf("number_of_times_each_philosopher_must_eat | %d\n",
		simu->philo->must_eat);
}
