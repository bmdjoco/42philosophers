/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:05:51 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/05 16:51:51 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philo
{
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	time_to_die;
	unsigned int	must_eat;
	int				*l_fork;
	int				*r_fork;
}	t_philo;

typedef struct	s_sim
{
	int		nb_philo;
	int		*fork;
	t_philo	*philo;
}	t_sim;

int		ft_atoi(const char *str);

long	get_time_milisec(void);

void	usage(void);
void	putstr(char *str, int fd);

void	put_philo(t_sim *simu);

t_sim	*define_sim(const char **av, int ac);

#endif
