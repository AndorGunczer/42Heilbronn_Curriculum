/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:32:56 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/25 13:21:10 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	int	i;

	i = 0;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		while ((*lst)->next != NULL)
		{
			*lst = (*lst)->next;
			i++;
		}
		(*lst)->next = new;
	}
}
