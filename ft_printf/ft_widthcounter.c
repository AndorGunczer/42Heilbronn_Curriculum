/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widthcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:40:11 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/02 11:36:54 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int  ft_isformat(char *str);

int ft_widthcounter(char *str, void *arg, int *i)
{
    char type;
    int width;

    type = ft_detertype(str, arg, i);
    if (type == 's')
        width = ft_strlen((char *)arg);
    if (type == 'c')
        width = 1;
    if (type == 'd' || type == 'i')
        width = ft_strlen(ft_itoa_long((long)arg));
    if (type == 'p')
        width = 2 + ft_strlen(ft_itoa_long((long)arg));
    if (type == 'u')
        width = ft_strlen(ft_itoa_long((unsigned int)arg));
    // while (*(str + *i) != '.' && ft_isformat(str + *i) != 1)
    //     (*i)++;
    return (width);
}

static int  ft_isformat(char *str)
{
    if (*str == 'd' || *str == 'i' || *str == 'c' || *str == 's' || *str == 'u'
    || *str == 'p' || *str == 'x' || *str == 'X')
        return (1);
    else
        return (0);
}
/* You have to create ft_itoa_hex() in order to handle x, X types */