/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 06:53:10 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/08 04:44:22 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

# define FLAG_MINUS 1
# define FLAG_ZERO 2
# define FLAG_HASH 4
# define FLAG_SPACE 8
# define FLAG_PLUS 16
# define FLAG_UPPER 32

int		ft_hex_len(unsigned long nbr);
int		ft_printf(const char *str, ...);
uint8_t	ft_flags(const char **str);
int		ft_padding(int len, char c);
int		ft_put_hex(uint8_t flag, int width, int precision, uint64_t ad);
int		ft_putchar(uint8_t flag, int width, int c);
int		ft_putnum(uint8_t flag, int width, int precision, int nbr);
int		ft_putpointer(uint8_t flag, int width, void *ptr);
int		ft_putsign(uint8_t flag, int nbr);
int		ft_putstr(uint8_t flag, int width, int precision, char *str);
int		ft_putu(uint8_t flag, int width, int precision, unsigned int nbr);
int		ft_specifier(const char **str, uint8_t flag, va_list args);
int		ft_write_hex(uint64_t ad, char *hex);
int		ft_write_number(int nbr);

#endif
