/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:33:37 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/25 09:41:16 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if ((dst != 0 || src != 0) && len != 0)
	{
		if (dst <= src)
		{
			i = 0;
			while (i < len)
			{
				*(char *)(dst + i) = *(char *)(src + i);
				i++;
			}
		}
		else if (src < dst)
		{
			i = len - 1;
			while (i > 0)
			{
				*(char *)(dst + i) = *(char *)(src + i);
				i--;
			}
			*(char *)(dst + i) = *(char *)(src + i);
		}
	}
	return (dst);
}
