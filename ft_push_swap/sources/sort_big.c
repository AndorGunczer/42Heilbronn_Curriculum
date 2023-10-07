/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:24:03 by agunczer          #+#    #+#             */
/*   Updated: 2021/11/05 16:24:52 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_copy(int *copy, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < size)
	{
		j = i;
		temp = copy[i];
		while (j > 0)
		{
			copy[j] = copy[j - 1];
			if (temp > copy[j - 1])
			{
				copy[j] = temp;
				break ;
			}
			j--;
		}
		if (temp < copy[j])
			copy[j] = temp;
		i++;
	}
}

void	simplify_input(int *copy, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->size_a)
	{
		while (j < stack->size_a)
		{
			if (stack->a[i] == copy[j])
			{
				stack->a[i] = j;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	radix_sort(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (is_sorted(stack->a, stack->size_a) != TRUE)
	{
		while (j < stack->size_a)
		{
			if ((stack->a[0] & (1 << i)) == 0)
				pb(stack->a, stack->b, &stack->size_a, &stack->size_b);
			else
			{
				ra(stack->a, stack->size_a);
				j++;
			}
		}
		while (stack->size_b != 0)
			pa(stack->a, stack->b, &stack->size_a, &stack->size_b);
		j = 0;
		i++;
	}
}

void	sort_big(t_stack *stack)
{
	int	*copy;
	int	i;

	copy = ft_calloc(sizeof(int), stack->size_a);
	i = 0;
	while (i < stack->size_a)
	{
		copy[i] = stack->a[i];
		i++;
	}
	sort_copy(copy, stack->size_a);
	simplify_input(copy, stack);
	radix_sort(stack);
}
