/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:03:34 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/02 21:30:23 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(t_stack **a, t_stack **b, char **str)
{
	if (check_sorted(*a) == 1)
	{
		if (check_duplicates(*a) == 0)
			print_error(a, str);
		if (size_list(*a) == 1)
			return ;
		else if (size_list(*a) == 2)
			sa(a);
		else if (size_list(*a) == 3)
			sort_3(a);
		else if (size_list(*a) == 4 || size_list(*a) == 5)
			sort_5(a, b);
		else
		{
			indexing(a);
			butterfly(a, b, formula_n(size_list(*a)));
		}
	}
}