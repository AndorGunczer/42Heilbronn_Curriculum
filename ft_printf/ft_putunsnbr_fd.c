/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:36:18 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/30 16:41:48 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putunsnbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putunsnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
