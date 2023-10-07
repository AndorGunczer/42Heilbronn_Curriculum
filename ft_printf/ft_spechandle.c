/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spechandle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:57:30 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/05 11:46:49 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void    ft_spechandle(char *str, void *arg, int *i)
// {
//     int blanks;
//     int flag;
//     int prec;

//     (*i)++;
//     if (contains_flag((str + *i), '-') == 1)
//         flag = 1;
//     else if (contains_flag((str + *i), '0') == 1)
//         flag = 2;
//     while (*(str + *i) != '.' && ft_isdigit(*(str + *i)) != 1 && ft_isformat(*(str + *i)) != 1)
//         (*i)++;
//     blanks = ft_atoi(*(str + *i));
//     while (*(str + *i) != '.' && ft_isformat(*(str + *i)) != 1)
//         (*i)++;
//     if (*(str + *i) == '.')
//         prec = ft_prechandle();
    
// }

#include "libftprintf.h"
#include <stdio.h>

static void     ft_putwidth(char c, int count);

void    ft_spechandle(char *str, void *arg, int *i)
{
    int flags;
    int field_width;
    int width;
    int precision;

    flags = ft_flaghandle(str, arg, i);
    field_width = ft_atoi((str + *i));
    width = ft_widthcounter(str, arg, i);
    precision = ft_deterprec(str, i);

    if (flags == 2)
    {
        ft_handletype(str, arg, i);
        ft_putwidth(' ', field_width - width); 
    }
    else if (flags == 1)
    {
        ft_putwidth('0', field_width - width);
        ft_handletype(str, arg, i);
    }
    else if (flags == 0)
    {
        ft_putwidth(' ', field_width - width);
        ft_handletype(str, arg, i);
        // ft_putchar_fd('\n', 1);
        // ft_putnbr_fd(width, 1);
        // ft_putchar_fd('\n', 1);
        // ft_putnbr_fd(field_width, 1);
    }
}

// static void    handler()
// {
//     if (flags == 2)
//     {
//         ft_handletype(str, arg, i);
//         ft_putwidth(' ', width - field_width); 
//     }
//     else if (flags == 1)
//     {
//         ft_putwidth('0', width - field_width);
//         ft_handletype();
//     }
//     else if (flags == 0)
//     {
//         ft_putwidth(' ', width - field_width);
//         ft_handletype();
//     }
// }

static void     ft_putwidth(char c, int count)
{
    while (count > 0)
    {
        ft_putchar_fd(c, 1);
        count--;
    }
}