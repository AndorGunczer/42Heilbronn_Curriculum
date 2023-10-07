/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detertype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:26:13 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/03 16:43:04 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int  ft_isformat(const char *str);

char    ft_detertype(const char *str, void *arg, int *i)
{
    int counter;

    counter = *i;
    while(ft_isformat(str + counter) != 1)
        counter++;
    if (*(str + counter) == 'c')
        return ('c');
    else if (*(str + counter) == 's')
        return ('s');
    else if (*(str + counter) == 'p')
        return ('p');
    else if (*(str + counter) == 'd')
        return ('d');
    else if (*(str + counter) == 'i')
        return ('i');
    else if (*(str + counter) == 'x')
        return ('x');
    else if (*(str + counter) == 'X')
        return ('X');
    else if (*(str + counter) == 'u')
        return ('u');
    return (0);
}

static int  ft_isformat(const char *str)
{
    if (*str == 'd' || *str == 'i' || *str == 'c' || *str == 's' || *str == 'u'
    || *str == 'p' || *str == 'x' || *str == 'X')
        return (1);
    else
        return (0);
}