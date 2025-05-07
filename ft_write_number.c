/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:29:54 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/04 04:06:39 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_number(int nbr)
{
	char	number[10];
	int		i;
	int		count;
	long	lg_num;

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
