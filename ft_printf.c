/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolhas- <mrolhas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:43:33 by mrolhas-          #+#    #+#             */
/*   Updated: 2023/02/11 17:31:15 by mrolhas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://www.youtube.com/watch?v=	3iX9a_l9W9Y
// Nice video to start and support

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
