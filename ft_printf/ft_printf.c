/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:16:40 by ymartiro          #+#    #+#             */
/*   Updated: 2024/03/17 17:17:43 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	printf_format(char c, va_list ap_)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap_, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap_, char *));
	else if (c == 'p')
		count += ft_putptr((unsigned long)va_arg(ap_, unsigned long));
	else if (c == 'd')
		count += print_digit(va_arg(ap_, int));
	else if (c == 'i')
		count += print_digit(va_arg(ap_, int));
	else if (c == 'u')
		count += print_unsigned_digit(va_arg(ap_, unsigned int));
	else if (c == 'x')
		count += put_hex_lower(va_arg(ap_, unsigned int));
	else if (c == 'X')
		count += put_hex_upper(va_arg(ap_, unsigned int));
	else
		count += write(1, &c, 1);
	return (count);
}

int	ft_printf(const char *p, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, p);
	while (p[i] != '\0')
	{
		if (p[i] == '%')
			count += printf_format(p[++i], ap);
		else
			count += write(1, &p[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

// int main()
// {
// 	char c = 'c';
// 	char *ptr = &c;
// 	ft_printf("%p ---- %d\n", ptr, 12);
// 	printf("%p ---- %d\n", ptr, 12);
// 	return (0);
// }