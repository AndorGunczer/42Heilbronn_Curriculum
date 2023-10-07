/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:08:55 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/03 11:21:21 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft/libft.h"

int ft_printf(const char *str, ...)
{
    va_list ap;
    void *arg;
    int *ptr;
    int i;

    va_start(ap, str);
    i = 0;
    ptr = &i;
    while (*(str + *ptr) != '\0')
    {
        if (*(str + *ptr) == '%')
        {
            arg = va_arg(ap, void*);
            ft_spechandle((char *)str, arg, ptr);
        }
        else
            ft_putchar_fd(*(str + *ptr), 1);
        (*ptr)++;
    }
    return (1);
}