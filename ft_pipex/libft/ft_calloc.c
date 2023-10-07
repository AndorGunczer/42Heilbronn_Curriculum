/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:32:11 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/25 09:40:11 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == 0)
	{
		return ((void *)0);
	}
	while (i < count * size)
	{
		*(char *)(ptr + i) = '\0';
		i++;
	}
	return (ptr);
}
