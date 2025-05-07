/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:54:39 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/06 22:27:48 by arimanuk         ###   ########.fr       */
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

void	find_position(t_stack **b, t_stack **a, t_stack **tmp)
{
	int	value;
	int	size;

	size = size_list(*b);
	value = (*tmp)->data;
	if ((*tmp)->index_b > size / 2)
	{
		while ((*b)->data != value)
			rrb(b, 1);
	}
	else if ((*tmp)->index_b < size / 2)
	{
		while ((*b)->data != value)
			rb(b, 1);
	}
	pa(a, b, 1);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	int		count;
	t_stack	*tmp;

	indexing_b(b);
	count = size_list(*b);
	while (count > 0)
	{
		tmp = *b;
		while (tmp)
		{
			if (count == tmp->index)
				find_position(b, a, &tmp);
			tmp = tmp->next;
		}
		count--;
	}
}
