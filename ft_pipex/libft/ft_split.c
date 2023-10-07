/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:33:44 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/28 14:41:33 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numstring(char const *s1, char c)
{
	int	comp;
	int	cles;

	comp = 0;
	cles = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			cles = 0;
		else if (cles == 0)
		{
			cles = 1;
			comp++;
		}
		s1++;
	}
	return (comp);
}

static int	numchar(char const *s2, char c, int i)
{
	int	length;

	length = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

static char	**freee(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (0);
}

static char	**affect(char const *s, char **dst, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = (char *)malloc(sizeof(char) * numchar(s, c, i) + 1);
		if (dst[j] == 0)
			return (freee((char const **)dst, j));
		while (s[i] != '\0' && s[i] != c)
		{
			dst[j][k] = s[i];
			k++;
			i++;
		}
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		l;

	if (!s)
		return (0);
	l = numstring(s, c);
	dst = (char **)malloc(sizeof(char *) * (l + 1));
	if (!dst)
		return (0);
	return (affect(s, dst, c, l));
}
