/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:29:30 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/25 22:26:46 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# define USAGE "./philo [number_of_philosofers] [time_to_die] [time_to_eat] [time_to_sleep]"

//#############################
//#          STATUS           #
//#############################
# define EAT "eating"
# define THINK "THINKING"
# define SLEEP "SLEEPING"
# define DIE "DIYING"

//typedef struct s_time
//{
//	double		time_to_die;
//	double		time_to_eat;
//	double		time_to_sleep;
//}

typedef struct s_philo
{
	int				id;
	int				forks;
	double			time_to_die;
	double			time_to_eat;
	double			time_to_sleep;
//	void *(*actions[3])(t_philo *);
	int				status;
	pthread_t		*thread;
	struct s_philo	*next;
}					t_philo;

	/******** PHILO_INFO *********/
t_philo	*get_philosofers(int ac, char **av);

	/********** ACTIONS **********/
void	get_actions(void *(*actions[3])(void *));
void	*start_eating(void *philo);
void	*start_thinking(void *philo);
void	*start_sleeping(void *philo);

	/*********** Utils ***********/
int	ft_atoi(char *s);

#endif
