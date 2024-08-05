/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:17:49 by ymartiro          #+#    #+#             */
/*   Updated: 2024/03/18 20:11:41 by ymartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(const char *p, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		print_digit(int d);
int		ft_putptr(unsigned long ptr);
int		print_unsigned_digit(unsigned int num);
int		put_hex_lower(unsigned int num);
int		put_hex_upper(unsigned int num);
char	*ft_itoa(int n);
char	*ft_unsigned_itoa(unsigned int n);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
int	    ft_atoi(const char *str);

#endif
