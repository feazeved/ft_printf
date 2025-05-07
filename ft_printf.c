/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 06:28:47 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/04 00:02:15 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int				count;
	va_list			args;
	unsigned char	flag;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			flag = ft_flags(&str);
			count += ft_specifier(&str, flag, args);
			if (*str)
				str++;
		}
		else
			count += write(1, str++, 1);
	}
	va_end(args);
	return (count);
}
