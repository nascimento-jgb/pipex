/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:36:53 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/16 11:13:49 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		lenght;
	va_list	args;

	va_start(args, format);
	i = 0;
	lenght = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			lenght += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			lenght += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (lenght);
}
