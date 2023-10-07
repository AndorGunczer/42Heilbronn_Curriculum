/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:34:47 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/28 18:34:39 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	if (start >= ft_strlen(s))
	{
		ptr = (char *) malloc(1);
		*ptr = '\0';
		return (ptr);
	}
	ptr = (char *) malloc(len + 1);
	if (ptr == 0)
		return ((char *)0);
	while (i < start)
		i++;
	ft_strlcpy(ptr, (s + i), len + 1);
	return (ptr);
}
