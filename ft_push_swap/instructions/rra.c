/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:24:37 by agunczer          #+#    #+#             */
/*   Updated: 2021/11/09 18:54:09 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>
#include <stdio.h>

void	rra(int	stack_a[], int size_a)
{
	int	i;
	int	last_num;

	ft_putendl_fd("rra", 1);
	i = size_a - 1;
	last_num = stack_a[i];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = last_num;
}
