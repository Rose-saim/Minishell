/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:11:23 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/26 12:14:04 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str2, const void *str1, size_t n)
{
	size_t			i;
	unsigned char	*str_1;
	unsigned char	*str_2;

	i = -1;
	str_1 = (unsigned char *)str1;
	str_2 = (unsigned char *)str2;
	if (!str1 && !str2)
		return (NULL);
	if (str_2 > str_1)
	{
		while (n-- > 0)
			str_2[n] = str_1[n];
	}
	else
	{
		while (++i < n)
			str_2[i] = str_1[i];
	}
	return (str_2);
}
