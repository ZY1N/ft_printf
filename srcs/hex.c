/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:28:49 by yinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 15:28:52 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rcasehashzero(t_struct *f, int hexlenp, char *s, char x)
{
	char c;

	c = findchar(f);
	if (c == '0' && f->hash == 2)
	{
		if (f->hash == 2 && x == 'x')
			f->nprinted += write(1, "0x", 2);
		else if (f->hash == 2 && x == 'X')
			f->nprinted += write(1, "0X", 2);
		while (f->width-- > 0)
			f->nprinted += write(1, &c, 1);
		while (f->precision-- > 0)
			f->nprinted += write(1, "0", 1);
		f->nprinted += write(1, s, hexlenp);
		return ;
	}
}

void	right_aligned_hex(t_struct *f, int hexlenp, char *s, char x)
{
	char c;

	c = findchar(f);
	if (c == '0' && f->hash == 2)
	{
		rcasehashzero(f, hexlenp, s, x);
		return ;
	}
	while (f->width > 0)
	{
		f->nprinted += write(1, &c, 1);
		f->width--;
	}
	if (f->hash == 2 && x == 'x')
		f->nprinted += write(1, "0x", 2);
	else if (f->hash == 2 && x == 'X')
		f->nprinted += write(1, "0X", 2);
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, s, hexlenp);
	free(s);
}

void	left_aligned_hex(t_struct *f, int hexlenp, char *s, char x)
{
	if (f->hash == 2 && x == 'x')
		f->nprinted += write(1, "0x", 2);
	else if (f->hash == 2 && x == 'X')
		f->nprinted += write(1, "0X", 2);
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, s, hexlenp);
	while (f->width > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
	free(s);
}

void	formatextractionhex(uintmax_t n, t_struct *f, char x, int hexlenp)
{
	char	*s;

	if (x == 'x')
		s = ft_itoa_base(n, 16);
	else if (x == 'X')
		s = ft_itoa_base_upper(n, 16);
	if (f->hash)
		f->hash = 2;
	if (n == 0)
	{
		hexlenp = 1;
		if (f->hash == 2)
			f->hash = 0;
		if (f->precisiontf && f->precision == 0)
			hexlenp = 0;
	}
	if (f->precisiontf && f->precision > hexlenp)
		f->precision = f->precision - hexlenp;
	else
		f->precision = 0;
	f->width = f->width - (f->precision + hexlenp) - f->hash;
	if (f->minus == 0)
		right_aligned_hex(f, hexlenp, s, x);
	else if (f->minus == 1)
		left_aligned_hex(f, hexlenp, s, x);
}

void	ifhex(t_struct *f, va_list ap, char x)
{
	uintmax_t	n;
	int			hexlenp;

	n = 0;
	if (f->length == 0)
		n = (unsigned int)va_arg(ap, unsigned int);
	else if (f->length == HH)
		n = (unsigned char)va_arg(ap, int);
	else if (f->length == H)
		n = (unsigned short)va_arg(ap, int);
	else if (f->length == LL)
		n = (unsigned long long int)va_arg(ap, uintmax_t);
	else if (f->length == L)
		n = (unsigned long int)va_arg(ap, uintmax_t);
	hexlenp = unsigned_nbr_len(n, 16);
	formatextractionhex(n, f, x, hexlenp);
}
