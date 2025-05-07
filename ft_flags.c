/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:28:08 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/05 02:38:14 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isflag(char c);

unsigned char	ft_flags(const char **str)
{
	unsigned char	bits;

	bits = 0;
	while (ft_isflag(**str))
	{
		if (**str == '-')
			bits |= FLAG_MINUS;
		if (**str == '0')
			bits |= FLAG_ZERO;
		if (**str == '#')
			bits |= FLAG_HASH;
		if (**str == ' ')
			bits |= FLAG_SPACE;
		if (**str == '+')
			bits |= FLAG_PLUS;
		(*str)++;
	}
	return (bits);
}

static int	ft_isflag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}
