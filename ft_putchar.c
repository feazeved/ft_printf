/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:38:27 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/02 18:54:59 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(unsigned char flag, int width, int c)
{
	int	count;

	count = 0;
	if (flag & FLAG_MINUS)
	{
		count += write(1, &c, 1);
		count += ft_padding(width - 1, ' ');
	}
	else
	{
		count += ft_padding(width - 1, ' ');
		count += write(1, &c, 1);
	}
	return (count);
}
