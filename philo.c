/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:13:34 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/25 22:36:37 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "philo.h"

int	main(int ac, char **av)
{
	t_philo *phs;
	void 	*(*actions[3])(void *);
	int		i;
	pthread_t t[10];

	get_actions(actions);
	phs = get_philosofers(ac, av);
	if (!phs)
		return (printf("%s\n", USAGE), 1);
	i = 0;
	while (phs->id)
	{
		pthread_create(&t[i++], NULL, actions[phs->id - 1], phs);
		sleep(1);
		phs = phs->next;
	}
	return (0);
}
