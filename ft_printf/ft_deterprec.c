/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deterprec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:55:52 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/03 11:39:35 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int  ft_isformat(char *str);

int ft_deterprec(char *str, int *i)
{
    while (ft_isformat((str + *i)) != 1 && *(str + *i) != '.')
        (*i)++;
    if (*(str + *i) == '.')
        return (ft_atoi(str + *i));
    else
        return (0);
}

static int  ft_isformat(char *str)
{
    if (*str == 'd' || *str == 'i' || *str == 'c' || *str == 's' || *str == 'u'
    || *str == 'p' || *str == 'x' || *str == 'X')
        return (1);
    else
        return (0);
}