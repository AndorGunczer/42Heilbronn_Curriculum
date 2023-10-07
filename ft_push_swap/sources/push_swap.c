/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:24:06 by agunczer          #+#    #+#             */
/*   Updated: 2021/11/09 17:39:09 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	array_len(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_stack	*stack;

	lst = NULL;
	stack = ft_calloc(sizeof(struct s_stack), 1);
	if (argc < 2)
		finish_complete(stack, lst);
	if (parse_input(argc, argv, &lst, stack) == 0)
		finish_error(ERROR, stack, lst);
	else
	{
		stack_assignment(stack, lst);
		fill_stack(stack, lst);
		if (is_sorted(stack->a, stack->size_a) == TRUE)
			finish_complete(stack, lst);
		else if (stack->size_a == 5 || stack->size_a == 3 || stack->size_a == 2)
			sort_small(stack);
		else
			sort_big(stack);
	}
	finish_complete(stack, lst);
}
