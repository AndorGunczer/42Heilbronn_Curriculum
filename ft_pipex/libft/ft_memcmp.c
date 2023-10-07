/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:33:26 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/25 09:41:07 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((s1 != 0 || s2 != 0) && n != 0)
	{
		while (i < n)
		{
			if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
				break ;
			i++;
		}
		if (i == n)
			i--;
		if (*(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
			return (0);
		else
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	}
	return (0);
}
