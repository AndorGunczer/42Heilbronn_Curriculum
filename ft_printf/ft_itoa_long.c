/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:32:49 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/02 12:55:41 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	num_count(long n);
static char	*assigner(long n, int i, int j, char *str);

char	*ft_itoa_long(long n)
{
	int		i;
	int		digits;
	int		j;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	digits = num_count(n);
	i = digits - 1;
	j = 0;
	str = malloc(sizeof(char) * (digits + 1));
	if (str == 0)
		return (0);
	return (assigner(n, i, j, str));
}

static	int	num_count(long n)
{
	int			i;
	long long	num;

	i = 0;
	num = n;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static char	*assigner(long n, int i, int j, char *str)
{	
	int	digits;

	digits = num_count(n);
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	if (n < 0)
	{
		*str = '-';
		n *= -1;
		j++;
	}
	while (i >= j)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	str[digits] = '\0';
	return (str);
}
