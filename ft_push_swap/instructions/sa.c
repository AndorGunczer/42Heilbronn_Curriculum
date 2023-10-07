/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:24:45 by agunczer          #+#    #+#             */
/*   Updated: 2021/11/09 18:54:15 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(int *stack_a, int size_a)
{
	int	temp;

	ft_putendl_fd("sa", 1);
	if (size_a > 1)
	{
		temp = stack_a[1];
		stack_a[1] = stack_a[0];
		stack_a[0] = temp;
	}
}
