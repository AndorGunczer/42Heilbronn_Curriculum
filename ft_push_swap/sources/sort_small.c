/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:23:58 by agunczer          #+#    #+#             */
/*   Updated: 2021/11/05 16:25:49 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	min_f(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->a[0];
	while (i < stack->size_a)
	{
		if (stack->a[i] < min)
			min = stack->a[i];
		i++;
	}
	return (min);
}

static int	max_f(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->a[0];
	while (i < stack->size_a)
	{
		if (stack->a[i] > max)
			max = stack->a[i];
		i++;
	}
	return (max);
}

void	sort_three(t_stack *stack)
{
	int	min;
	int	max;

	min = min_f(stack);
	max = max_f(stack);
	if (stack->a[0] == min && stack->a[1] == max)
	{
		rra(stack->a, stack->size_a);
		sa(stack->a, stack->size_a);
	}
	else if (stack->a[1] == min && stack->a[2] == max)
		sa(stack->a, stack->size_a);
	else if (stack->a[2] == min && stack->a[1] == max)
		rra(stack->a, stack->size_a);
	else if (stack->a[0] == max && stack->a[1] == min)
		ra(stack->a, stack->size_a);
	else if (stack->a[0] == max && stack->a[2] == min)
	{
		sa(stack->a, stack->size_a);
		rra(stack->a, stack->size_a);
	}
}

void	sort_five(t_stack *stack)
{
	int	min;
	int	i;
	int	cnt;

	cnt = 0;
	while (cnt < 2)
	{
		min = min_f(stack);
		i = 0;
		while (stack->a[i] != min)
			i++;
		if (i != 0 && i < stack->size_a / 2)
			while (stack->a[0] != min)
				ra(stack->a, stack->size_a);
		else if (i != 0)
			while (stack->a[0] != min)
				rra(stack->a, stack->size_a);
		pb(stack->a, stack->b, &stack->size_a, &stack->size_b);
		cnt++;
	}
	sort_three(stack);
	pa(stack->a, stack->b, &stack->size_a, &stack->size_b);
	pa(stack->a, stack->b, &stack->size_a, &stack->size_b);
}

void	sort_small(t_stack *stack)
{
	if (stack->size_a == 3 || stack->size_a == 2)
		sort_three(stack);
	else if (stack->size_a == 5)
		sort_five(stack);
}
