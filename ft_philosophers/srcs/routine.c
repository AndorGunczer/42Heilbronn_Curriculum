/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:56:23 by agunczer          #+#    #+#             */
/*   Updated: 2022/02/17 12:57:13 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static int	eat(t_philo *philo)
{
	philo->state = eating;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->mutex_lfork);
		ft_log(philo, " has taken a fork", 0, NULL);
		if (*philo->death == 1)
			return (1);
		pthread_mutex_lock(philo->mutex_rfork);
		ft_log(philo, " has taken a fork", 0, NULL);
	}
	else
	{
		pthread_mutex_lock(philo->mutex_rfork);
		ft_log(philo, " has taken a fork", 0, NULL);
		if (*philo->death == 1)
			return (1);
		pthread_mutex_lock(philo->mutex_lfork);
		ft_log(philo, " has taken a fork", 0, NULL);
	}
	if (ft_sleep(philo->input->time_to_eat, philo) == 1)
		return (1);
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->mutex_rfork);
	pthread_mutex_unlock(philo->mutex_lfork);
	return (0);
}

static int	ft_sleeping(t_philo *philo)
{
	philo->state = sleeping;
	if (ft_sleep(philo->input->time_to_sleep, philo) == 1)
		return (1);
	return (0);
}

static int	think(t_philo *philo)
{
	philo->state = thinking;
	if (*(philo->death) == 1)
		return (1);
	ft_log(philo, NULL, 0, NULL);
	usleep(150);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->mutex_lfork == philo->mutex_rfork && one_philo(philo))
		return (NULL);
	if (philo->id % 2 == 0)
		think(philo);
	while (1)
	{
		if (eat(philo) == 1)
			break ;
		if (++philo->amount_meal == philo->input->number_of_meals)
			break ;
		if (ft_sleeping(philo) == 1)
			break ;
		if (think(philo) == 1)
			break ;
	}
	pthread_mutex_unlock(philo->mutex_lfork);
	pthread_mutex_unlock(philo->mutex_rfork);
	return (NULL);
}
