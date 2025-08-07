/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:38:36 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/07 23:23:38 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_philo(t_philo *philo)
{
	if (philo->is_dead)
		free(philo->is_dead);
	if (philo->is_end)
		free(philo->is_end);
	if (philo)
		free(philo);
}

void	free_simu(t_sim *simu)
{
	if (simu->fork)
		free(simu->fork);
	if (simu->table)
		free_philo(simu->table);
	if (simu)
		free(simu);
}

void	putstr(char *str, int fd)
{
	int	i;
	if (!str)
		return ;
	i = -1;
	while(str[++i])
		write(fd, &str[i], 1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r')
		|| str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}


