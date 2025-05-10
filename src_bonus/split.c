/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:46:39 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/10 21:15:44 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen1(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	find(char c, char *del)
{
	int	i;

	i = 0;
	while (del[i] != '\0')
	{
		if (c == del[i])
			return (1);
		i++;
	}
	return (0);
}

static int	getword(char const *s, char *del)
{
	int	i;
	int	count_word;
	int	len;

	i = 0;
	count_word = 0;
	len = ft_strlen1(s);
	while (s && s[i])
	{
		while (s[i] && find(s[i], del) == 1)
			i++;
		while (s[i] && find(s[i], del) != 1)
			i++;
		if (find(s[i - 1], del) == 1 && (i == len))
			count_word--;
		count_word++;
	}
	return (count_word);
}

static int	malloc_char(char const *s, char *del, int *i, int *start)
{
	int	len;

	len = 0;
	while (find(s[*i], del) == 1)
		(*i)++;
	*start = *i;
	while (s[*i] && find(s[*i], del) != 1)
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

char	**ft_split(char const *s, char *del)
{
	int		i;
	char	**buffer;
	int		ind;
	int		count_word;
	int		start;

	i = 0;
	ind = -1;
	count_word = getword(s, del);
	buffer = (char **)malloc((count_word + 1) * sizeof(char *));
	if (buffer == NULL)
		return (NULL);
	buffer[count_word] = NULL;
	while (count_word--)
	{
		buffer[++ind] = func_copy(s, malloc_char(s, del, &i, &start), start);
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
