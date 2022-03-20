/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:11:23 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/26 12:14:45 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	j;

	j = 0;
	if (!ft_strncmp(s2, "", 1))
		return ((char *)s1);
	while (len > 0 && s1[j] && ft_strlen(s2) <= len)
	{
		if (ft_strncmp(s1 + j, s2, ft_strlen(s2)) == 0)
			return ((char *)s1 + j);
		j++;
		len--;
	}
	return (NULL);
}
