/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:24:31 by agunczer          #+#    #+#             */
/*   Updated: 2021/11/09 18:54:05 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>
#include <stdio.h>

void	rb(int	stack_b[], int size_b)
{
	int	i;
	int	first_num;

	ft_putendl_fd("rb", 1);
	i = 0;
	first_num = stack_b[i];
	while (i < size_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[size_b - 1] = first_num;
}
