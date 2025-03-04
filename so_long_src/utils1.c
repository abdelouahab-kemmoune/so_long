/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:08:47 by akemmoun          #+#    #+#             */
/*   Updated: 2025/03/03 15:23:19 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_len(long n)
{
	int	counter;

	counter = 0;
	while (n > 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_ispositive(long n)
{
	int		len;
	char	*array;

	len = count_len(n);
	if (n == 0)
		len++;
	array = (char *)malloc(len + 1);
	if (!array)
		return (NULL);
	array[len--] = '\0';
	while (len >= 0)
	{
		array[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (array);
}

char	*ft_isnegative(long n)
{
	int		len;
	char	*array;

	n *= -1;
	len = count_len(n);
	array = (char *)malloc(sizeof(char) * (len + 2));
	if (!array)
		return (NULL);
	array[len + 1] = '\0';
	while (len > 0)
	{
		array[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	array[len] = '-';
	return (array);
}

char	*ft_itoa(int n)
{
	char	*array;
	long	nb;

	nb = n;
	if (nb < 0)
		array = ft_isnegative(nb);
	if (nb >= 0)
		array = ft_ispositive(nb);
	return (array);
}
