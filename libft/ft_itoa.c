/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:11:23 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/26 12:13:09 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	count_num(int num)
{
	unsigned int	i;

	i = 1;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num / 10)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*num_neg(int n)
{
	char	*str;
	int		i;

	i = count_num(n);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	str[0] = '-';
	while (i > 1)
	{
		str[--i] = -1 * (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

char	*num_pstv(int n)
{
	char	*str;
	int		i;

	i = count_num(n);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	while (i > 0)
	{
		str[--i] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = count_num(n);
	str = NULL;
	if (n < 0)
		str = num_neg(n);
	else if (n >= 0)
		str = num_pstv(n);
	return (str);
}
