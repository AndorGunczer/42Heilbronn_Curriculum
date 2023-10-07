/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 07:36:31 by agunczer          #+#    #+#             */
/*   Updated: 2022/02/17 12:56:11 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_putchar_fd('\n', fd);
}

void	ft_putstr_buff(char *s, char **ptr)
{
	while (*s)
	{
		*(*ptr)++ = *s;
		s++;
	}
}

void	ft_putnbr_buff(long n, char **ptr)
{
	if (n < 0)
	{
		*(*ptr)++ = '-';
		ft_putnbr_buff(-n, ptr);
	}
	else if (n >= 10)
	{
		ft_putnbr_buff(n / 10, ptr);
		*(*ptr)++ = n % 10 + '0';
	}
	else
		*(*ptr)++ = n + '0';
}
