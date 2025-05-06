/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:54:09 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/02 20:37:54 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_list(t_stack *a)
{
	int	count;

	count = 0;
	while (a != NULL)
	{
		a = a->next;
		count++;
	}
	return (count);
}

void	move_two_smallest_to_b(int data, int len, t_stack **a, t_stack **b)
{
	int		count;
	t_stack	*tmp;

	tmp = *a;
	count = 1;
	while (data != tmp->data)
	{
		tmp = tmp->next;
		count++;
	}
	if (len / 2 < count)
	{
		while (tmp->next != NULL)
			rra(a);
		rra(a);
		pb(a, b);
	}
	else
	{
		while (--count)
			ra(a);
		pb(a, b);
	}
}

void	indexing(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*current;

	current = *a;
	tmp = *a;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	tmp = (*a)->next;
	while (current)
	{
		while (tmp)
		{
			if (current->data > tmp->data)
				current->index++;
			tmp = tmp->next;
		}
		tmp = *a;
		current = current->next;
	}
}

long long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	return (sign * res);
}
