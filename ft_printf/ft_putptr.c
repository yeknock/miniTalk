/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:02:31 by ymartiro          #+#    #+#             */
/*   Updated: 2024/03/18 22:16:40 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	unsigned int	int_len(unsigned long n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

static	char	letters_check(unsigned long remainder)
{
	if (remainder == 10)
		return ('a');
	else if (remainder == 11)
		return ('b');
	else if (remainder == 12)
		return ('c');
	else if (remainder == 13)
		return ('d');
	else if (remainder == 14)
		return ('e');
	return ('f');
}

static	char	*string_reverse(char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			*rev_str;

	i = 0;
	if (str)
	{
		j = ft_strlen(str) - 1;
		rev_str = (char *)malloc((sizeof(char) * ft_strlen(str)) + 1);
		if (!rev_str)
			return (0);
		while (str[i] != '\0')
		{
			rev_str[i] = str[j];
			i++;
			j--;
		}
		rev_str[i] = '\0';
		free(str);
		return (rev_str);
	}
	return (0);
}

static	char	*hex_lower(unsigned long n)
{
	char			*str;
	unsigned int	rem;
	unsigned int	i;

	rem = 0;
	i = 0;
	str = (char *)malloc((sizeof(char) * int_len(n)) + 1);
	if (!str)
		return (0);
	while (n)
	{
		rem = n % 16;
		if (rem <= 9)
			str[i] = rem + 48;
		else
			str[i] = letters_check(rem);
		n = n / 16;
		i++;
	}
	str[i] = '\0';
	return (string_reverse(str));
}

int	ft_putptr(unsigned long ptr)
{
	unsigned int	i;
	char			*str;
	char			c;

	i = 0;
	write(1, "0x", 2);
	if (ptr == 0)
	{
		c = '0';
		return (write(1, &c, 1) + 2);
	}
	str = hex_lower(ptr);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	free(str);
	return (i + 2);
}
