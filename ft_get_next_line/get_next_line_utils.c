/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:02:20 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/31 16:08:32 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(unsigned int count, unsigned int size)
{
	unsigned int	i;
	void			*ptr;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == 0)
	{
		free (ptr);
		return ((void *)0);
	}
	while (i < count * size)
	{
		*(char *)(ptr + i) = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen(s1);
	i = 0;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
	{
		free(ptr);
		return ((void *)0);
	}
	while (i < len)
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = (char *) ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (ptr == 0)
		return (NULL);
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
	if (s1)
		free((void *)s1);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	i = 0;
	j = 0;
	if (start >= ft_strlen(s))
	{
		return (NULL);
	}
	ptr = (char *) ft_calloc(len + 1, sizeof(char));
	if (ptr == 0)
	{
		free(ptr);
		return ((char *)0);
	}
	while (i < start)
		i++;
	while (j < len)
	{
		ptr[j] = s[i];
		j++;
		i++;
	}
	return (ptr);
}
