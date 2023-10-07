/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:00:40 by agunczer          #+#    #+#             */
/*   Updated: 2021/06/26 12:54:07 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;

	if (!lst || !f || !del)
		return (0);
	tail = ft_lstnew(f(lst));
	if (!tail)
		return (0);
	head = tail;
	lst = lst->next;
	while (lst)
	{
		head->next = ft_lstnew(f(lst));
		if (!head->next)
		{
			ft_lstclear(&tail, del);
			return (0);
		}
		lst = lst->next;
	}
	head->next = NULL;
	return (tail);
}
