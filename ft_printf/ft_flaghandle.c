/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flaghandle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:26:50 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/05 11:42:02 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int  ft_isformat(char *str);
static int  contains_flag(char *str, char c);

int    ft_flaghandle(char *str, void *arg, int *i)
{
    int flag;

    while (*(str + *i) != '-' && ft_isdigit(*(str + *i)) != 1 && ft_isformat(str + *i) != 1)
        (*i)++;
    if (contains_flag((str + *i), '-') == 1)
        flag = 2;
    else if (contains_flag((str + *i), '0') == 1)
        flag = 1;
    else
        flag = 0;
    if (*(str + *i) == '-' || *(str + *i) == '0')
        (*i)++;
    return(flag);
}

static int  contains_flag(char *str, char c)
{
    while (*str != '.' && ft_isdigit(*str) != 1 && ft_isformat(str) != 1)
    {
        if (*str == c)
            return (1);
    }
    if (*str == c)
        return (1);
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