/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolhas- <mrolhas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:43:33 by mrolhas-          #+#    #+#             */
/*   Updated: 2023/04/22 20:37:25 by mrolhas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://www.youtube.com/watch?v=	3iX9a_l9W9Y
// Nice video to start and support

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_checkprintf(char str, va_list args)
{
	if (str == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str == 'd' || str == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	else if (str == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (str == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (str == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (str == '%')
		return (ft_putchar(str));
	else if (str == 'p')
		return (ft_putptr(args));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len = len + ft_checkprintf(str[i], args);
			i++;
		}
		else
			len = len + ft_putchar(str[i++]);
	}
	va_end(args);
	return (len);
}

/*int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len = len + ft_checkprintf(str[i], args);
			i++;
		}
		else
			len = len + ft_putchar(str[i++]);
	}
	va_end(args);
	return (len);
}*/
