/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:54:39 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/09 14:51:20 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	root_n(int size)
{
	int	i;

	i = 0;
	if (i < size / 2)
	{
		while (i * i <= size)
		{
			if (i * i == size)
				return (i);
			else
				i++;
		}
	}
	return (0);
}

int	log_n(int size)
{
	int	count;

	count = 0;
	while (size > 1)
	{
		size = size / 2;
		count++;
	}
	return (count);
}

int	formula_n(int size)
{
	return ((root_n(size) * 3) / 2 + log_n(size) - 1);
}

int	get_position(t_stack *stack, int value) //gpt
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->data == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	find_position(t_stack **b, t_stack **a, t_stack *target) //gpt
{
	int		size_b;
	int		pos;
	
	size_b = size_list(*b);
	pos = get_position(*b, target->data); // Position of the value in b (0 = top)

	if (pos <= size_b / 2)
	{
		while ((*b)->data != target->data)
			rb(b, 1);
	}
	else
	{
		while ((*b)->data != target->data)
			rrb(b, 1);
	}
	pa(a, b, 1);
}
// void	find_position(t_stack **b, t_stack **a, t_stack **tmp)
// {
// 	int	value;
// 	int	size;

// 	size = size_list(*b);
// 	value = (*tmp)->data;
// 	if ((*tmp)->index_b > size / 2)
// 	{
// 		while ((*b)->data != value)
// 			rrb(b, 1);
// 	}
// 	else if ((*tmp)->index_b < size / 2)
// 	{
// 		while ((*b)->data != value)
// 			rb(b, 1);
// 	}
// 	pa(a, b, 1);
// }
int	find_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0); // or handle as error
	max = stack->data;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	get_moves_to_top(t_stack *stack, int value) //gpt
{
	int	pos;
	int	size;
	
	pos = get_position(stack, value);
	size = size_list(stack);
	if (pos <= size / 2)
		return (pos); // rb
	return (size - pos); // rrb
}
void	move_b_to_aa(t_stack **a, t_stack **b)
{
while (*b)
{
    int max = find_max(*b);
    int pos = get_position(*b, max);
    if (pos <= size_list(*b) / 2)
        while ((*b)->data != max)
            rb(b, 1);
    else
        while ((*b)->data != max)
            rrb(b, 1);
    pa(a, b, 1);
}
}

void	move_b_to_a(t_stack **a, t_stack **b) // gpt
{
	t_stack	*tmp;
	t_stack	*best;
	int		min_moves;
	int		moves;
	
	while (*b)
	{
		tmp = *b;
		best = tmp;
		min_moves = get_moves_to_top(*b, tmp->data);
		
		while (tmp)
		{
			moves = get_moves_to_top(*b, tmp->data);
			if (moves < min_moves)
			{
				min_moves = moves;
				best = tmp;
			}
			tmp = tmp->next;
		}
		find_position(b, a, best);
	}
}

// 
// void	move_b_to_a(t_stack **a, t_stack **b)
// {
	// int		count;
	// t_stack	*tmp;
// 
	// indexing_b(b);
	// count = size_list(*b);
	// while (count > 0)
	// {
		// tmp = *b;
		// while (tmp)
		// {
			// if (count == tmp->index)
				// find_position(b, a, &tmp);
			// tmp = tmp->next;
		// }
		// count--;
	// }
// }
// 
