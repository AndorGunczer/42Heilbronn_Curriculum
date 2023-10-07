/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:34:19 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/25 10:48:03 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	if (i < dstsize && *(char *)(src + i) != '\0')
	{
		while (*(char *)(src + i) != '\0' && i < dstsize - 1)
		{
			*(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	if (i < dstsize)
		*(dst + i) = '\0';
	while (*(src + i) != '\0')
		i++;
	return (i);
}
