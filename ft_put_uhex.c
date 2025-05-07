/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:35:33 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/05 02:31:03 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uhex_m(unsigned char flag, int wid, int prec, unsigned long ad);
static int	ft_uhex_r(unsigned char flag, int wid, int prec, unsigned long ad);
static int	ft_uhex_z(unsigned char flag, int width, unsigned long ad);

int	ft_put_uhex(unsigned char flag, int width, int precision, unsigned long ad)
{
	if (flag & FLAG_MINUS)
		return (ft_uhex_m(flag, width, precision, ad));
	else
	{
		if ((flag & FLAG_ZERO) && precision == -1)
			return (ft_uhex_z(flag, width, ad));
		else
			return (ft_uhex_r(flag, width, precision, ad));
	}
}

static int	ft_uhex_m(unsigned char flag, int wid, int prec, unsigned long ad)
{
	int	count;

	count = 0;
	if ((flag & FLAG_HASH) && ad)
		count += ft_putstr(0, 0, -1, "0X");
	if (prec != -1)
		count += ft_padding(prec - ft_hex_len(ad), '0');
	if (prec != 0 || ad)
		count += ft_write_hex(ad, "0123456789ABCDEF");
	count += ft_padding(wid - count, ' ');
	return (count);
}

static int	ft_uhex_r(unsigned char flag, int wid, int prec, unsigned long ad)
{
	int	count;

	count = 0;
	if ((flag & FLAG_HASH) && ad)
		count += 2;
	if ((ft_hex_len(ad) > prec && prec != 0) || (prec == 0 && ad))
		count += ft_padding(wid - count - ft_hex_len(ad), ' ');
	else
		count += ft_padding(wid - count - prec, ' ');
	if ((flag & FLAG_HASH) && ad)
		ft_putstr(0, 0, -1, "0X");
	if (prec != -1)
		count += ft_padding(prec - ft_hex_len(ad), '0');
	if (prec != 0 || ad)
		count += ft_write_hex(ad, "0123456789ABCDEF");
	return (count);
}

static int	ft_uhex_z(unsigned char flag, int width, unsigned long ad)
{
	int	count;

	count = 0;
	if ((flag & FLAG_HASH) && ad)
		count += ft_putstr(0, 0, -1, "0X");
	count += ft_padding(width - count - ft_hex_len(ad), '0');
	count += ft_write_hex(ad, "0123456789ABCDEF");
	return (count);
}
