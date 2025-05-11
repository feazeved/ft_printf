/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:37:46 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/08 18:27:32 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wid_prec_atoi(const char **str, int *width, int *precision);

int	ft_specifier(const char **str, unsigned char flag, va_list args)
{
	int	prec;
	int	wid;

	ft_wid_prec_atoi(str, &wid, &prec);
	if (**str == 'c')
		return (ft_putchar(flag, wid, (char)va_arg(args, int)));
	else if (**str == 's')
		return (ft_putstr(flag, wid, prec, va_arg(args, char *)));
	else if (**str == 'p')
		return (ft_putpointer(flag, wid, va_arg(args, void *)));
	else if (**str == 'd' || **str == 'i')
		return (ft_putnum(flag, wid, prec, va_arg(args, int)));
	else if (**str == 'u')
		return (ft_putu(flag, wid, prec, va_arg(args, unsigned int)));
	else if (**str == 'x')
		return (ft_put_hex(flag, wid, prec, va_arg(args, unsigned int)));
	else if (**str == 'X')
		return (ft_put_hex(flag + 32, wid, prec, va_arg(args, unsigned int)));
	else if (**str == '%')
		return (ft_putchar(0, 0, 37));
	return (0);
}

static void	ft_wid_prec_atoi(const char **str, int *width, int *precision)
{
	int	wid;
	int	pre;

	wid = 0;
	while (**str >= '0' && **str <= '9')
	{
		wid = wid * 10 + (**str - '0');
		(*str)++;
	}
	pre = -1;
	if (**str == '.')
	{
		(*str)++;
		pre = 0;
		while (**str >= '0' && **str <= '9')
		{
			pre = pre * 10 + (**str - '0');
			(*str)++;
		}
	}
	*precision = pre;
	*width = wid;
}
