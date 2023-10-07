/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlower_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:50:06 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/30 16:24:01 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	ft_converthex(int hex);

void	ft_puthexlower_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("80000000", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_puthexlower_fd(-n, fd);
	}
	else if (n >= 16)
	{
		ft_puthexlower_fd(n / 16, fd);
		ft_putchar_fd(ft_converthex(n % 16), fd);
	}
	else
		ft_putchar_fd(ft_converthex(n), fd);
}

static char	ft_converthex(int hex)
{
	if (hex >= 0 && hex <= 9)
		return (hex + '0');
	if (hex == 10)
		return ('a');
	if (hex == 11)
		return ('b');
	if (hex == 12)
		return ('c');
	if (hex == 13)
		return ('d');
	if (hex == 14)
		return ('e');
	if (hex == 15)
		return ('f');
	return (0);
}