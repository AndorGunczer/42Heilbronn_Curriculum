/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:33:07 by agunczer          #+#    #+#             */
/*   Updated: 2021/10/28 12:03:27 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_struct;

	new_struct = malloc(sizeof(t_list));
	if (new_struct == 0)
		return (0);
	new_struct->content = content;
	new_struct->next = NULL;
	return (new_struct);
}
