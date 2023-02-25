/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:45:59 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/25 22:26:15 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "philo.h"

void	get_actions(void *(*actions[3])(void *))
{
	actions[0] = &start_eating;
	actions[1] = &start_thinking;
	actions[2] = &start_sleeping;
}

void	*start_eating(void *philo)
{
	t_philo *p;

	p = (t_philo *) philo;
	printf("%dms %d has taken a fork\n", 10, p->id);
	printf("%dms %d is eating\n", 10, p->id);
	return (0);
}

void	*start_thinking(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	printf("%dms %d is thinking\n", 10, p->id);
	return (0);
}

void	*start_sleeping(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	printf("%dms %d is sleeping\n", 10, p->id);
	return (0);
}

t_philo	*get_philosofers(int ac, char **av)
{
	t_philo	*phs;
	int		phs_nb;
	int		i;

	if (ac != 5)
		return (0);
	phs_nb = ft_atoi(av[1]);
	if (phs_nb < 3 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (0);
	phs = (t_philo *) malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!phs)
		return (0);
	i = -1;
	while (++i < phs_nb)
	{
		phs[i].id = i + 1;
		phs[i].forks = 1;
		phs[i].time_to_die = ft_atoi(av[2]);
		phs[i].time_to_eat = ft_atoi(av[3]);
		phs[i].time_to_sleep = ft_atoi(av[4]);
		if (i != phs_nb - 1)
			phs[i].next = &phs[i + 1];
	}
	phs[i - 1].next = &phs[0];
	return (phs);
}
