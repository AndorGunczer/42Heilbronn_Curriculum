/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:33:15 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/28 14:24:40 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (dst != 0 || src != 0)
	{
		while (i < n)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			if (*(unsigned char *)(src + i) == (unsigned char)c)
			{
				return (dst + i + 1);
			}
			i++;
		}
	}
	return ((void *)0);
}
