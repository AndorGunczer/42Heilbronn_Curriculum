/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:34:15 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/25 12:12:10 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (*(dst + i) && i < dstsize)
		i++;
	while (*(src + j) && i + j < dstsize - 1)
	{
		*(dst + i + j) = *(src + j);
		j++;
	}
	if (i < dstsize)
		*(dst + i + j) = '\0';
	return (i + ft_strlen(src));
}
