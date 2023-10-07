/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:27:52 by agunczer          #+#    #+#             */
/*   Updated: 2021/11/09 18:46:10 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./sources/libft/libft.h"
# include <stdio.h>
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define TRUE	1
# define	FALSE	0
# define ERROR	"Error"

typedef struct s_stack{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

void	sa(int *stack_a, int size_a);
void	sb(int *stack_b, int size_b);
void	ss(int *stack_a, int *stack_b, int size_a, int size_b);
void	ra(int	stack_a[], int size_a);
void	rb(int	stack_b[], int size_b);
void	rr(int stack_a[], int stack_b[], int size_a, int size_b);
void	rra(int	stack_a[], int size_a);
void	rrb(int	stack_b[], int size_b);
void	rrr(int stack_a[], int stack_b[], int size_a, int size_b);
void	pa(int	*stack_a, int	*stack_b, int *size_a, int *size_b);
void	pb(int	*stack_a, int	*stack_b, int *size_a, int *size_b);

int		parse_input(int argc, char *argv[], t_list	**lst, t_stack *stack);
int		check_input(int argc, char *argv[], t_list	**lst, int start);
int		isint(char *argv);
int		isnumber(char *argv);
int		isdupe(char *argv, t_list *lst);

void	finish_error(char *msg, t_stack *stack, t_list *lst);
void	finish_complete(t_stack *stack, t_list *lst);

void	fill_stack(t_stack *stack, t_list *lst);
void	lst_to_stack_a(int *stack_a, int *i, t_list *lst);
void	stack_assignment(t_stack *stack, t_list *lst);
int		is_sorted(int *stack_a, int size_a);

void	sort_big(t_stack *stack);
void	sort_copy(int *copy, int size);
void	simplify_input(int *copy, t_stack *stack);
void	radix_sort(t_stack *stack);

void	sort_small(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack);

void	free_array(char **arr);
void	free_array_i(int *arr);

int		array_len(char **str);
int		main(int argc, char **argv);

#endif