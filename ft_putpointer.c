/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:37:27 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/05 02:43:07 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned char flag, int width, void *ptr)
{
	int				count;
	unsigned long	address;

	count = 0;
	address = (unsigned long)ptr;
	if (!ptr)
		return (ft_putstr(flag, width, -1, "(nil)"));
	if (flag & FLAG_MINUS)
	{
		count += ft_putstr(0, 0, -1, "0x");
		count += ft_put_hex(0, 0, -1, address);
		count += ft_padding(width - count, ' ');
	}
	else
	{
		count += ft_padding(width - 2 - ft_hex_len(address), ' ');
		count += ft_putstr(0, 0, -1, "0x");
		count += ft_put_hex(0, 0, -1, address);
	}
	return (count);
}
