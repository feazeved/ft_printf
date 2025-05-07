/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:32:22 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/04 04:51:43 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(unsigned char flag, int width, int precision, char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str && (precision >= 6 || precision == -1))
		return (ft_putstr(flag, width, -1, "(null)"));
	else if (!str && precision != -1)
		return (ft_putstr(flag, width, precision, ""));
	if (flag & FLAG_MINUS)
	{
		while (str[i] && (i < precision || precision == -1))
			count += write(1, &str[i++], 1);
		count += ft_padding(width - i, ' ');
	}
	else
	{
		while (str[i] && (i < precision || precision == -1))
			i++;
		count += ft_padding(width - i, ' ');
		i = 0;
		while (str[i] && (i < precision || precision == -1))
			count += write(1, &str[i++], 1);
	}
	return (count);
}
