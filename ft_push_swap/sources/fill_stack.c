/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:24:15 by agunczer          #+#    #+#             */
/*   Updated: 2021/11/05 16:16:28 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(int *stack_a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	stack_assignment(t_stack *stack, t_list *lst)
{
	int	max_size;

	max_size = ft_lstsize(lst);
	stack->size_a = max_size;
	stack->size_b = 0;
	stack->a = ft_calloc(sizeof(int), max_size);
	stack->b = ft_calloc(sizeof(int), max_size);
}

void	lst_to_stack_a(int *stack_a, int *i, t_list *lst)
{
	stack_a[*i] = lst->content;
	(*i)++;
}

void	fill_stack(t_stack *stack, t_list *lst)
{
	int	i;

	i = 0;
	if (stack->a == NULL)
		finish_error(ERROR, stack, lst);
	else
		ft_lstiter(lst, stack->a, &i, &lst_to_stack_a);
}
