/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:05:51 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/06 23:10:34 by bdjoco           ###   ########.fr       */
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
	int				num;
	int				must_eat;
	unsigned int	time;
	unsigned int	time_to_eat;
	unsigned int	time_to_die;
	unsigned int	time_to_sleep;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

typedef struct	s_sim
{
	int				nb_philo;
	pthread_mutex_t	*fork;
	t_philo			*philo;
}	t_sim;

int		ft_atoi(const char *str);
int		msleep(unsigned int time);

long	get_time_milisec(void);

void	usage(void);
void	putstr(char *str, int fd);

void	put_philo(t_sim *simu);

t_sim	*define_sim(const char **av, int ac);

#endif
