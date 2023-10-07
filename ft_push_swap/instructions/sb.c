/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:24:48 by agunczer          #+#    #+#             */
/*   Updated: 2021/11/09 18:54:23 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(int *stack_b, int size_b)
{
	int	temp;

	ft_putendl_fd("sb", 1);
	if (size_b > 1)
	{
		temp = stack_b[1];
		stack_b[1] = stack_b[0];
		stack_b[0] = temp;
	}
}
