/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:16:00 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/04 17:35:42 by bdjoco           ###   ########.fr       */
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
