/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:06:23 by ymartiro          #+#    #+#             */
/*   Updated: 2024/02/20 21:26:55 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	int_len(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		while (n)
		{
			i++;
			n = n / 10;
		}
		return (i);
	}
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static	char	*fill_str(char *str, int n)
{
	int	i;

	i = int_len(n);
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	while (i > 0 && n)
	{
		str[i - 1] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = int_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(i + 1);
	if (!str)
		return (0);
	fill_str(str, n);
	return (str);
}
