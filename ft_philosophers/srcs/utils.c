/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:09:44 by agunczer          #+#    #+#             */
/*   Updated: 2022/02/17 13:54:19 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ft_log(t_philo *philo, char *event, int exception, char *ptr)
{
	long	time;
	char	buff[128];

	ptr = buff;
	time = get_time() - philo->input->start;
	ft_putnbr_buff(time, &ptr);
	ft_putstr_buff("ms philo ", &ptr);
	ft_putnbr_buff(philo->id, &ptr);
	if (event == NULL)
	{
		if (philo->state == eating)
			ft_putstr_buff(" started eating", &ptr);
		else if (philo->state == sleeping)
			ft_putstr_buff(" started sleeping", &ptr);
		else if (philo->state == thinking)
			ft_putstr_buff(" started thinking", &ptr);
	}
	else
		ft_putstr_buff(event, &ptr);
	*ptr = '\0';
	pthread_mutex_lock(philo->mutex_print);
	if (*philo->death != 1)
		ft_putendl_fd(buff, 1);
	pthread_mutex_unlock(philo->mutex_print);
	return (1);
}

int	one_philo(t_philo *philo)
{
	long	start;
	long	now;

	start = get_time();
	usleep(philo->input->time_to_die * 1000);
	now = get_time();
	ft_log(philo, " has died", 0, NULL);
	*philo->death = 1;
	return (1);
}

static int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	else if ((c == '\n' || c == '\t' || c == '\v' || c == '\t' || c == '\r'
			|| c == '\f'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	int		num;

	i = 0;
	j = 0;
	num = 0;
	while (ft_isspace(*(str + i)) == 1 && str[i] != '\0')
	{
		i++;
		j++;
	}
	if (str[i] == '\0')
		return (0);
	if (*(str + j) == '-' || *(str + j) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
	{
		num = num * 10 + (*(str + i) - '0');
		i++;
	}
	if (*(str + j) == '-')
		num *= -1;
	return (num);
}

int	is_num(char *str)
{
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (*str > 57 || *str < 48)
			return (0);
		str++;
	}
	return (1);
}
