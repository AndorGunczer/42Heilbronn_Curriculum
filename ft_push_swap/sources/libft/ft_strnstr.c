/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:34:34 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/25 12:02:18 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(haystack + i) != '\0' && i < len)
	{
		while (*(haystack + i) == *(needle + j) && *(haystack + i) != '\0'
			&& i < len)
		{
			if (j == ft_strlen((char *)needle) - 1)
				return ((char *)(haystack + i - j));
			i++;
			j++;
		}
		if (j == 0)
			i++;
		j = 0;
	}
	if (ft_strncmp((char *)needle, "", 1) == 0)
		return ((char *)haystack);
	return (0);
}
