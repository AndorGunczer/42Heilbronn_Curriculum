/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:59:08 by agunczer          #+#    #+#             */
/*   Updated: 2022/02/17 13:52:11 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	destroy_mutexes(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(philo[0].mutex_end);
	free(philo[0].mutex_end);
	pthread_mutex_destroy(philo[0].mutex_print);
	free(philo[0].mutex_print);
	pthread_mutex_destroy(philo[0].mutex_death);
	free(philo[0].mutex_death);
	if (philo[0].death != NULL)
		free((void *)philo[0].death);
	while (i < philo[0].input->num_of_philo)
	{
		pthread_mutex_destroy(philo[i].mutex_rfork);
		free(philo[i].mutex_rfork);
		i++;
	}
	return (0);
}

int	launch_philo(t_philo *philo, t_input *input)
{
	int	i;

	i = 0;
	while (i < input->num_of_philo)
	{
		pthread_create(&philo[i].philosopher, NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < input->num_of_philo)
	{
		pthread_join(philo[i].philosopher, NULL);
		i++;
	}
	return (0);
}

int	fill_philosophers(t_input *input, t_philo *philo, int i)
{
	while (i < input->num_of_philo)
	{
		philo[i].mutex_rfork = (pthread_mutex_t *)
			malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init(philo[i].mutex_rfork, NULL))
			return (1);
		i++;
	}
	i = 0;
	while (i < input->num_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].death = philo[0].death;
		philo[i].mutex_end = philo[0].mutex_end;
		philo[i].mutex_death = philo[0].mutex_death;
		philo[i].mutex_print = philo[0].mutex_print;
		philo[i].mutex_lfork = philo[(i + 1) % input->num_of_philo].mutex_rfork;
		philo[i].input = input;
		philo[i].amount_meal = 0;
		philo[i].last_meal = get_time();
		i++;
	}
	launch_philo(philo, input);
	return (0);
}

t_philo	*create_philosopher(t_input *input)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *) malloc(input->num_of_philo * sizeof(t_philo));
	philo->death = (int *) malloc(sizeof(int));
	philo->mutex_end = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	philo->mutex_death = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	philo->mutex_print = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	if (philo->death == NULL || philo->mutex_end == NULL
		|| philo->mutex_death == NULL || philo->mutex_print == NULL)
		return (NULL);
	if (pthread_mutex_init(philo->mutex_end, NULL))
		return (NULL);
	if (pthread_mutex_init(philo->mutex_death, NULL))
		return (NULL);
	if (pthread_mutex_init(philo->mutex_print, NULL))
		return (NULL);
	*philo->death = 0;
	i = 0;
	if (fill_philosophers(input, philo, i))
		return (NULL);
	return (philo);
}
