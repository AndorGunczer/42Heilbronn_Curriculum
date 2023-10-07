/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:34:44 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/25 09:42:52 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	isset(char s1, char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*ptr;

	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	if (set == 0)
		return (ft_strdup(s1));
	if (ft_strncmp(s1, "", 1) == 0)
		return (ft_strdup(s1));
	while (isset(*(s1 + i), (char *)set) == 1 && *(s1 + i) != '\0')
		i++;
	while (isset(*(s1 + j), (char *)set) == 1 && j > 0)
		j--;
	if (i >= j)
		return (ft_strdup(""));
	ptr = (char *) malloc(sizeof(char) * ((j) - (i) + 2));
	if (ptr == 0)
		return (ptr);
	ft_strlcpy(ptr, s1 + i, j - i + 2);
	return (ptr);
}

static int	isset(char s1, char *set)
{
	while (*set != '\0')
	{
		if (*set == s1)
			return (1);
		set++;
	}
	return (0);
}
