/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:35:53 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/04 00:57:57 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hex(unsigned long ad, char *hex)
{
	int	count;

	count = 0;
	if (ad == 0)
		return (write(1, "0", 1));
	if (ad >= 16)
		count += ft_write_hex(ad / 16, hex);
	count += write(1, &hex[ad % 16], 1);
	return (count);
}
