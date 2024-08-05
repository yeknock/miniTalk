/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:20:15 by ymartiro          #+#    #+#             */
/*   Updated: 2024/03/17 17:20:43 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	print_digit(int d)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(d);
	count = ft_putstr(str);
	free(str);
	return (count);
}

int	print_unsigned_digit(unsigned int num)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_unsigned_itoa((int)num);
	count = ft_putstr(str);
	free(str);
	return (count);
}
