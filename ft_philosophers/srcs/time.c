/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:39:48 by agunczer          #+#    #+#             */
/*   Updated: 2022/02/17 12:56:04 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

long	get_time(void)
{
	struct timeval	time;
	long			miliseconds;

	gettimeofday(&time, NULL);
	miliseconds = time.tv_sec * 1000;
	miliseconds += time.tv_usec / 1000;
	return (miliseconds);
}

int	ft_sleep(long duration, t_philo *philo)
{
	long	start;
	long	now;

	start = get_time();
	now = get_time();
	ft_log(philo, NULL, 0, NULL);
	while (now - start < duration)
	{	
		if (*philo->death == 1)
			return (1);
		if (now - philo->last_meal >= philo->input->time_to_die)
		{
			ft_log(philo, " has died", 0, NULL);
			*philo->death = 1;
			return (1);
		}
		usleep(100);
		now = get_time();
	}
	return (0);
}
