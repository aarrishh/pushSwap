/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:57:31 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/09 17:20:44 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char    *ft_strdup(const char *s)
{
    char    *buffer;
    int     i;
    
    i = 0;
    while (s[i])
        i++;
    buffer = (char *)malloc(i * sizeof(char));
    i = 0;
    while (s[i])
    {
        buffer[i] = s[i];
        i++;
    }
    buffer[i] = '\0';
    return (buffer);
}

int	main(int argc, char **argv)
{
	int			i;
	char		**str;
	char		*s;
	t_stack		*a;
	t_stack		*b;


	a = NULL;
	b = NULL;
	str = NULL;
	i = 1;
	if (argc >= 2)
	{
		while (argv[i])
		{
			if (check_white_spaces(argv[i]) == 1)
				print_error(&a);
			s = ft_strdup(argv[i]);
			str = ft_split(s, "\n\f\v\r\t ");
			helper(str, &a);
			free_split(str);
			free(s);
			i++;
		}
		check(&a, &b);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
