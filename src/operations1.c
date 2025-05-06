/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:48:32 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/02 20:27:03 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*idk;

	if ((*b)->next != NULL)
	{
		idk = *b;
		tmp = *b;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*b) = (*b)->next;
		idk->next = NULL;
		tmp->next = idk;
	}
	write (1, "rb\n", 3);
}

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*idk;

	tmp = *a;
	idk = tmp;
	if ((*a)->next != NULL)
	{
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		while (idk->next != NULL)
			idk = idk->next;
		tmp->next = NULL;
		idk->next = *a;
		*a = idk;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*idk;

	tmp = *b;
	idk = tmp;
	if ((*b)->next != NULL)
	{
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		while (idk->next != NULL)
			idk = idk->next;
		tmp->next = NULL;
		idk->next = *b;
		*b = idk;
	}
	write (1, "rrb\n", 4);
}
