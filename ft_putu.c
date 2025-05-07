/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:38:09 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/05 02:22:50 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_unumber(unsigned int nbr);
static int	ft_unumlen(unsigned int nbr);
static int	ft_putu_m(int width, int precision, unsigned int nbr);
static int	ft_putu_z(int width, int precision, unsigned int nbr);

int	ft_putu(unsigned char flag, int width, int precision, unsigned int nbr)
{
	int	count;

	count = 0;
	if (flag & FLAG_MINUS)
		count += ft_putu_m(width, precision, nbr);
	else
	{
		if (flag & FLAG_ZERO && precision == -1)
			count += ft_putu_z(width, precision, nbr);
		else
		{
			if (ft_unumlen(nbr) > precision && precision != 0)
				count += ft_padding(width - count - ft_unumlen(nbr), ' ');
			else if (precision == 0 && nbr)
				count += ft_padding(width - count - ft_unumlen(nbr), ' ');
			else
				count += ft_padding(width - count - precision, ' ');
			if (precision != -1)
				count += ft_padding(precision - ft_unumlen(nbr), '0');
			if (precision != 0 || nbr)
				count += ft_write_unumber(nbr);
		}
	}
	return (count);
}

static int	ft_putu_z(int width, int precision, unsigned int nbr)
{
	int	count;

	count = 0;
	if (ft_unumlen(nbr) > precision)
		count += ft_padding(width - count - ft_unumlen(nbr), '0');
	else
		count += ft_padding(width - count - precision, '0');
	if (precision != -1)
		count += ft_padding(precision - ft_unumlen(nbr), '0');
	count += ft_write_unumber(nbr);
	return (count);
}

static int	ft_putu_m(int width, int precision, unsigned int nbr)
{
	int	count;

	count = 0;
	if (precision != -1)
		count += ft_padding(precision - ft_unumlen(nbr), '0');
	if (precision != 0 || nbr)
		count += ft_write_unumber(nbr);
	count += ft_padding(width - count, ' ');
	return (count);
}

static int	ft_write_unumber(unsigned int nbr)
{
	char			number[10];
	int				i;
	int				count;
	unsigned long	lg_num;

	i = 0;
	count = 0;
	lg_num = nbr;
	if (lg_num == 0)
		return (write(1, "0", 1));
	if (lg_num < 0)
		lg_num = -lg_num;
	while (lg_num)
	{
		number[i] = lg_num % 10 + '0';
		lg_num /= 10;
		i++;
	}
	while (i--)
		count += write(1, &number[i], 1);
	return (count);
}

static int	ft_unumlen(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
