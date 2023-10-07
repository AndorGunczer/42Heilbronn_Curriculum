/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:24:18 by agunczer          #+#    #+#             */
/*   Updated: 2021/11/05 16:15:26 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	finish_error(char *msg, t_stack *stack, t_list *lst)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack)
		free(stack);
	if (lst)
		ft_lstclear(&lst, &free);
	if (msg != NULL)
	{
		ft_putendl_fd(msg, 2);
		exit(1);
	}
	else
	{
		ft_putendl_fd("Something Went Wrong", 2);
		exit(1);
	}
}

void	finish_complete(t_stack *stack, t_list *lst)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack)
		free(stack);
	if (lst)
		ft_lstclear(&lst, &free);
	exit(0);
}
