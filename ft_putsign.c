/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:29:28 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/04 03:59:49 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putsign(unsigned char flag, int nbr)
{
	int	count;

	count = 0;
	if ((flag & FLAG_PLUS) && nbr >= 0)
		count += write(1, "+", 1);
	else if (!(flag & FLAG_PLUS) && (flag & FLAG_SPACE) && nbr >= 0)
		count += write(1, " ", 1);
	else if (nbr < 0)
		count += write(1, "-", 1);
	return (count);
}
