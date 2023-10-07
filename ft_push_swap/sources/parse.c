/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:24:12 by agunczer          #+#    #+#             */
/*   Updated: 2021/11/09 17:39:35 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	isnumber(char *argv)
{
	int	boolean;

	if (argv[0] == '-' && !argv[1])
		return (0);
	if (argv[0] == '-' || argv[0] == '+' || ft_isdigit(argv[0]) == 1)
		boolean = 1;
	else
		return (0);
	argv++;
	while (*argv != '\0')
	{
		boolean = ft_isdigit(*argv);
		if (boolean == 0)
			return (boolean);
		argv++;
	}
	return (boolean);
}

int	isint(char *argv)
{
	long long	num;

	num = ft_atoi_l(argv);
	if (num > MAX_INT || num < MIN_INT)
		return (0);
	return (1);
}

int	isdupe(char *argv, t_list *lst)
{
	int	num;
	int	x;

	num = ft_atoi(argv);
	x = 1;
	while (x == 1 || (lst)->next != NULL)
	{
		if ((lst)->next == NULL)
			x = 0;
		if ((lst)->content != num)
		{
			if ((lst)->next != NULL)
				(lst) = (lst)->next;
		}
		else
			return (0);
	}
	ft_lstadd_back(&lst, ft_lstnew(num));
	return (1);
}

int	check_input(int argc, char *argv[], t_list	**lst, int start)
{
	int		i;

	i = start;
	if (isnumber(argv[i]) == 1 && isint(argv[i]) == 1)
	{
		*lst = ft_lstnew(ft_atoi(argv[start]));
		i++;
	}
	else
		return (0);
	while (i < argc)
	{
		if (isnumber(argv[i]) == 0)
			return (0);
		if (isint(argv[i]) == 0)
			return (0);
		if (isdupe(argv[i], *lst) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	parse_input(int argc, char *argv[], t_list **lst, t_stack *stack)
{
	char	**formatted_input;
	int		arg_len;
	int		i;

	if (argc == 2)
	{
		formatted_input = ft_split(argv[1], ' ');
		if (formatted_input[0] == '\0')
		{
			free_array(formatted_input);
			finish_complete(stack, *lst);
		}
		arg_len = array_len(formatted_input);
		i = check_input(arg_len, formatted_input, lst, 0);
		free_array(formatted_input);
		return (i);
	}
	else
	{
		i = check_input(argc, argv, lst, 1);
		return (i);
	}
}
