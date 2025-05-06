/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:15:54 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/02 19:16:43 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing_b(t_stack **b)
{
	int		count;
	t_stack	*tmp;

	tmp = *b;
	count = 0;
	while (tmp)
	{
		tmp->index_b = 0;
		tmp = tmp->next;
	}
	tmp = (*b);
	while (tmp)
	{
		tmp->index_b = count;
		count++;
		tmp = tmp->next;
	}
}

void	butterfly(t_stack **a, t_stack **b, int n)
{
	int	count;

	count = 0;
	while (*a != NULL)
	{
		if ((*a)->index <= count)
		{
			pb(a, b);
			rb(b);
			count++;
		}
		else if ((*a)->index <= count + n)
		{
			pb(a, b);
			count++;
		}
		else
			ra(a);
	}
	while (*b)
	{
		move_b_to_a(a, b);
		pa(a, b);
	}
}
