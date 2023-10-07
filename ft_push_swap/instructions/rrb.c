/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:24:40 by agunczer          #+#    #+#             */
/*   Updated: 2021/11/09 18:54:10 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>
#include <stdio.h>

void	rrb(int	stack_b[], int size_b)
{
	int	i;
	int	last_num;

	ft_putendl_fd("rrb", 1);
	i = size_b - 1;
	last_num = stack_b[i];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = last_num;
}
