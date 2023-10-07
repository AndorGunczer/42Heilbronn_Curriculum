/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:24:28 by agunczer          #+#    #+#             */
/*   Updated: 2021/11/09 18:54:03 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>
#include <stdio.h>

void	ra(int	stack_a[], int size_a)
{
	int	i;
	int	first_num;

	ft_putendl_fd("ra", 1);
	i = 0;
	first_num = stack_a[i];
	while (i < size_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[size_a - 1] = first_num;
}
