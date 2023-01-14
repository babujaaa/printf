/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolhas- <mrolhas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:13:15 by mrolhas-          #+#    #+#             */
/*   Updated: 2023/01/14 15:26:47 by mrolhas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_printf(const char *, ...)
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
