/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:57:31 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/02 22:01:07 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *a)
{
	if (a == NULL)
		return (0);
	while (a->next != NULL)
	{
		if (a->data < a->next->data)
			a = a->next;
		else
			return (1);
	}
	return (0);
}

void	add_back(t_stack *node, t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL)
	{
		*a = node;
		return ;
	}
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

t_stack	*create_node(int res)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	new_node->data = res;
	new_node->next = NULL;
	return (new_node);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free (str);
	str = NULL;
}

int	main(int argc, char **argv)
{
	int			i;
	char		**str;
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	str = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	if (argc >= 2)
	{
		while (argv[i])
		{
			if (str_contain_only_white_spaces(argv[i]) == 1)
				print_error(&a, str);
			str = ft_split(argv[i], ' ');
			helper(str, &a);
			free_split(str);
			i++;
		}
		check(&a, &b, str);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}


void	helper(char **str, t_stack **a)
{
	t_stack		*node;
	long long	res;
	int			j;

	j = 0;
	res = 0;
	node = NULL;
	while (str[j])
	{
		res = ft_atoi(str[j]);
		check_max_min(res, a, str);
		if (res == -1)
		{
			free_split(str);
			print_error(a, str);
		}
		node = create_node(res);
		add_back(node, a);
		j++;
	}
}