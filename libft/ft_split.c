/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:11:23 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/26 12:14:24 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	wordcount(char const *s, char const c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
			i++;
		while (*s != c && *s)
			s++;
		if (*s)
			s++;
	}
	return (i);
}

size_t	length_word(char const *s, char const c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	size_t	x;
	size_t	i;

	x = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	new_str = ft_calloc(wordcount(s, c) + 1, sizeof(char *));
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			new_str[x] = ft_calloc(sizeof(char), length_word(s + i, c) + 1);
			ft_memcpy(new_str[x++], s + i, length_word(s + i, c));
			i += length_word(s + i, c);
		}
	}
	return (new_str);
}
