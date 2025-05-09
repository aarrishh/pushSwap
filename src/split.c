/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:46:39 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/09 17:19:45 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int in_str(char c, const char *str)
{
	int i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return 1;
	return 0;
}

static int	getword(char const *s, char *c)
{
	int	i;
	int	count_word;

	i = 0;
	count_word = 0;
	while (s && s[i])
	{
		if(in_str(s[i], c) == 0)
		{
			count_word++;
			while(s[i] && in_str(s[i], c) == 0)
				i++;
		}
		i++;
	}
	return (count_word);
}

static int	malloc_char(char const *s, char *c, int *i, int *start)
{
	int	len;

	len = 0;
	while (in_str(s[*i], c) == 1)
		(*i)++;
	*start = *i;
	while (s[*i] && in_str(s[*i], c) == 0)
	{
		len++;
		(*i)++;
	}
	return (len);
}

static char	*func_copy(char const *s, int len_current_line, int start)
{
	int		j;
	char	*line;

	j = 0;
	line = malloc((len_current_line + 1) * sizeof(char));
	while (j < len_current_line)
	{
		line[j] = s[start + j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	**ft_split(char const *s, char *c)
{
	int		i;
	char	**buffer;
	int		ind;
	int		count_word;
	int		start;

	i = 0;
	ind = -1;
	count_word = getword(s, c);
	start = 0;
	buffer = (char **)malloc((count_word + 1) * sizeof(char *));
	if (buffer == NULL)
		return (NULL);
	buffer[count_word] = NULL;
	while (count_word--)
	{
		buffer[++ind] = func_copy(s, malloc_char(s, c, &i, &start), start);
		if (!buffer[ind])
		{
			while (ind)
				free(buffer[--ind]);
			free(buffer);
			return (NULL);
		}
	}
	return (buffer);
}
