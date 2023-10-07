/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:34:26 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/25 09:42:22 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ptr;

	ptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ptr == 0)
		return (0);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(ptr + i) = f(i, *(s + i));
		++i;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
