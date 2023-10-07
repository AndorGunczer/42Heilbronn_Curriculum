/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:34:31 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/25 09:42:27 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((*s1 != '\0' || *s2 != '\0') && i < n)
	{
		if (*(unsigned char *)(s1) != *(unsigned char *)(s2))
			return (*(unsigned char *)(s1) - *(unsigned char *)(s2));
		s1++;
		s2++;
		i++;
	}
	s1--;
	s2--;
	if (*(unsigned char *)(s1) != *(unsigned char *)(s2))
		return (*(unsigned char *)(s1) - *(unsigned char *)(s2));
	else
		return (0);
}
