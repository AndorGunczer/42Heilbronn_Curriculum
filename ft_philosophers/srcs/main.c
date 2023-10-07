/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:09:29 by agunczer          #+#    #+#             */
/*   Updated: 2022/02/17 13:04:33 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static int	check_input(int argc, char **argv)
{
	int	num;

	num = 1;
	if (argc < 5 || argc > 6)
	{
		printf("\033[0;31m\tWrong number of Arguments\n\tPhilosophers quit.");
		return (1);
	}
	if (is_num(argv[1]) == 0)
		num = 0;
	if (is_num(argv[2]) == 0)
		num = 0;
	if (is_num(argv[3]) == 0)
		num = 0;
	if (is_num(argv[4]) == 0)
		num = 0;
	if (argc == 6)
	{
		if (is_num(argv[5]) == 0)
			num = 0;
	}
	if (num == 0)
		return (1);
	return (0);
}

static int	init_input(t_input *input, char **argv)
{
	input->num_of_philo = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		input->number_of_meals = ft_atoi(argv[5]);
	else
		input->number_of_meals = -1;
	gettimeofday(&(input->timestamp), NULL);
	input->start = (input->timestamp.tv_sec * 1000)
		+ (input->timestamp.tv_usec / 1000);
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_input		input;
	t_philo		*philo;

	i = 1;
	if (check_input(argc, argv) == 1)
		return (EXIT_FAILURE);
	if (init_input(&input, argv) == 1)
		return (EXIT_FAILURE);
	philo = create_philosopher(&input);
	if (philo == NULL)
	{
		destroy_mutexes(philo);
		free(philo);
		return (EXIT_FAILURE);
	}
	destroy_mutexes(philo);
	free(philo);
	return (EXIT_SUCCESS);
}
