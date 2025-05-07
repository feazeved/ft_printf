/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:32:06 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/05 02:25:43 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnum_m(unsigned char flag, int width, int precision, int nbr);
static int	ft_putnum_r(unsigned char flag, int wid, int prec, int nbr);
static int	ft_putnum_z(unsigned char flag, int width, int nbr);
static int	ft_numlen(int nbr);

int	ft_putnum(unsigned char flag, int width, int precision, int nbr)
{
	if (flag & FLAG_MINUS)
		return (ft_putnum_m(flag, width, precision, nbr));
	else
	{
		if ((flag & FLAG_ZERO) && precision == -1)
			return (ft_putnum_z(flag, width, nbr));
		else
			return (ft_putnum_r(flag, width, precision, nbr));
	}
}

static int	ft_putnum_m(unsigned char flag, int width, int precision, int nbr)
{
	int	count;

	count = 0;
	count += ft_putsign(flag, nbr);
	if (precision != -1)
		count += ft_padding(precision - ft_numlen(nbr), '0');
	if (precision != 0 || nbr)
		count += ft_write_number(nbr);
	count += ft_padding(width - count, ' ');
	return (count);
}

static int	ft_putnum_r(unsigned char flag, int wid, int prec, int nbr)
{
	int	count;

	count = 0;
	count += ((flag & FLAG_PLUS) && nbr >= 0);
	count += (!(flag & FLAG_PLUS) && (flag & FLAG_SPACE) && (nbr >= 0));
	count += (nbr < 0);
	if ((ft_numlen(nbr) > prec && prec != 0) || (prec == 0 && nbr))
		count += ft_padding(wid - count - ft_numlen(nbr), ' ');
	else
		count += ft_padding(wid - count - prec, ' ');
	if (nbr < 0 || ((flag & FLAG_PLUS) && nbr >= 0)
		|| (!(flag & FLAG_PLUS) && (flag & FLAG_SPACE) && (nbr >= 0)))
		count--;
	count += ft_putsign(flag, nbr);
	if (prec != -1)
		count += ft_padding(prec - ft_numlen(nbr), '0');
	if (prec != 0 || nbr)
		count += ft_write_number(nbr);
	return (count);
}

static int	ft_putnum_z(unsigned char flag, int width, int nbr)
{
	int	count;

	count = 0;
	count += ft_putsign(flag, nbr);
	count += ft_padding(width - count - ft_numlen(nbr), '0');
	count += ft_write_number(nbr);
	return (count);
}

static int	ft_numlen(int nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
