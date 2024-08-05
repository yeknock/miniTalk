/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexnum_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:06:15 by ymartiro          #+#    #+#             */
/*   Updated: 2024/03/18 20:08:56 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	unsigned int	int_len(unsigned int n)
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

static	char	letters_check(int remainder)
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

static	char	*hex_lower(unsigned int n)
{
	char			*str;
	int				rem;
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

int	put_hex_lower(unsigned int num)
{
	unsigned int	i;
	char			*str;
	char			c;

	i = 0;
	if (num == 0)
	{
		c = '0';
		return (write(1, &c, 1));
	}
	str = hex_lower(num);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	free(str);
	return (i);
}
