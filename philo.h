/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:05:51 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/04 17:30:59 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	time_to_die;
	int				*l_fork;
	int				*r_fork;
}	t_philo;

typedef struct s_sim
{
	int		nb_philo;
	t_philo	**philo;
}	t_sim;

void	usage(void);
void	putstr(char *str, int fd);

#endif
