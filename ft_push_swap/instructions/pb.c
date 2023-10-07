/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:24:26 by agunczer          #+#    #+#             */
/*   Updated: 2021/11/09 18:55:05 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rarra(int	stack_a[], int size_a)
{
	int	i;
	int	first_num;

	i = 0;
	first_num = stack_a[i];
	while (i < size_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[size_a - 1] = first_num;
}

static void	rrabbe(int	stack_b[], int size_b)
{
	int	i;
	int	last_num;

	i = size_b - 1;
	last_num = stack_b[i];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = last_num;
}

void	pb(int	*stack_a, int	*stack_b, int *size_a, int *size_b)
{
	ft_putendl_fd("pb", 1);
	if (*size_a > 0)
	{
		(*size_b)++;
		stack_b[*size_b - 1] = stack_a[0];
		rrabbe(stack_b, *size_b);
		rarra(stack_a, *size_a);
		stack_a[*size_a - 1] = 0;
		(*size_a)--;
	}
}
