/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:33:55 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/08 04:46:08 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_m(unsigned char flag, int wid, int prec, unsigned long ad);
static int	ft_hex_z(unsigned char flag, int wid, unsigned long ad);
static int	ft_hex_r(unsigned char flag, int wid, int prec, unsigned long ad);

int	ft_put_hex(unsigned char flag, int width, int precision, unsigned long ad)
{
	int	count;

	count = 0;
	if (flag & FLAG_MINUS)
		return (ft_hex_m(flag, width, precision, ad));
	else
	{
		if ((flag & FLAG_ZERO) && precision == -1)
			return (ft_hex_z(flag, width, ad));
		else
			return (ft_hex_r(flag, width, precision, ad));
	}
}

static int	ft_hex_m(unsigned char flag, int wid, int prec, unsigned long ad)
{
	int	count;

	count = 0;
	if ((flag & FLAG_HASH) && ad && (flag & FLAG_UPPER))
		count += write(1, "0X", 2);
	else if ((flag & FLAG_HASH) && ad)
		count += write(1, "0x", 2);
	if (prec != -1)
		count += ft_padding(prec - ft_hex_len(ad), '0');
	if ((prec != 0 || ad) && (flag & FLAG_UPPER))
		count += ft_write_hex(ad, "0123456789ABCDEF");
	else if (prec != 0 || ad)
		count += ft_write_hex(ad, "0123456789abcdef");
	count += ft_padding(wid - count, ' ');
	return (count);
}

static int	ft_hex_z(unsigned char flag, int wid, unsigned long ad)
{
	int	count;

	count = 0;
	if ((flag & FLAG_HASH) && ad && (flag & FLAG_UPPER))
		count += write(1, "0X", 2);
	else if ((flag & FLAG_HASH) && ad)
		count += write(1, "0x", 2);
	count += ft_padding(wid - count - ft_hex_len(ad), '0');
	if (flag & FLAG_UPPER)
		count += ft_write_hex(ad, "0123456789ABCDEF");
	else
		count += ft_write_hex(ad, "0123456789abcdef");
	return (count);
}

static int	ft_hex_r(unsigned char flag, int wid, int prec, unsigned long ad)
{
	int	count;

	count = 0;
	if ((flag & FLAG_HASH) && ad)
		count += 2;
	if ((ft_hex_len(ad) > prec && prec != 0) || (prec == 0 && ad))
		count += ft_padding(wid - count - ft_hex_len(ad), ' ');
	else
		count += ft_padding(wid - count - prec, ' ');
	if ((flag & FLAG_HASH) && ad && (flag & FLAG_UPPER))
		write(1, "0X", 2);
	else if ((flag & FLAG_HASH) && ad)
		write(1, "0x", 2);
	if (prec != -1)
		count += ft_padding(prec - ft_hex_len(ad), '0');
	if ((prec != 0 || ad) && (flag & FLAG_UPPER))
		count += ft_write_hex(ad, "0123456789ABCDEF");
	else if (prec != 0 || ad)
		count += ft_write_hex(ad, "0123456789abcdef");
	return (count);
}
