/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:38:45 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/02 18:55:27 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_padding(int len, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i++ < len)
	{
		count += write(1, &c, 1);
	}
	return (count);
}
