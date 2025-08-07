/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:17:45 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/08 00:35:15 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_mutex
{
	int				state;
	pthread_mutex_t	mutex;
}	t_mutex;

typedef struct s_philo
{
	int				num;
	int				must_eat;
	t_mutex			*is_dead;
	t_mutex			*is_end;
	unsigned int	time;
	unsigned int	time_to_eat;
	unsigned int	time_to_die;
	unsigned int	time_to_sleep;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

typedef struct s_sim
{
	int				nb_philo;
	t_philo			*table;
	pthread_mutex_t	*fork;
}	t_sim;

void	usage(void);
void	free_simu(t_sim *simu);
void	putstr(char *str, int fd);
void	*philo_routine(void *arg);
void	*watcher_routine(void *arg);

long	get_time_milisec(void);

int		is_dead(t_philo *philo);
int		is_end(t_philo *philo);
int		ft_atoi(const char *str);
int		msleep(long time);

t_sim	*init_simu(int ac, const char **av);

#endif
