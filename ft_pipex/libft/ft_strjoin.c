/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:34:12 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/25 09:34:13 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == 0)
		return (ptr);
	while (*(s1 + i) != '\0')
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	while (*(s2) != '\0')
	{
		*(ptr + i) = *(s2);
		s2++;
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
