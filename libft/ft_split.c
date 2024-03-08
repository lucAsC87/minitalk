/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucavall <lucavall@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:26:48 by lucavall          #+#    #+#             */
/*   Updated: 2023/11/13 12:56:09 by lucavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_counter(const char *str, char c)
{
	size_t	counter;
	int		i;
	int		word;

	counter = 0;
	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (!word && str[i] != c)
		{
			word = 1;
			counter++;
		}
		else if (word && str[i] == c)
			word = 0;
		i++;
	}
	return (counter);
}

static char	*alt_str_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	free_split(char **split, int limit)
{
	int	i;

	i = 0;
	while (i <= limit)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((words_counter(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = alt_str_dup(s, index, i);
			if (!split[j - 1])
				return (free_split(split, --j), NULL);
			index = -1;
		}
	}
	split[j] = 0;
	return (split);
}
