/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:45:52 by yinzhang          #+#    #+#             */
/*   Updated: 2019/05/26 13:45:54 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	right_aligned_octal(t_struct *f, int widthp, int octlenp, char *s)
{
	char c;

	if (f->zero && !f->precisiontf)
		c = '0';
	else
		c = ' ';
	while (widthp > 0)
	{
		f->nprinted += write(1, &c, 1);
		widthp--;
	}
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	if (f->hash == 1)
		f->nprinted += write(1, "0", 1);
	f->nprinted += write(1, s, octlenp);
}

void	left_aligned_octal(t_struct *f, int widthp, int octlenp, char *s)
{
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	if (f->hash == 1)
		f->nprinted += write(1, "0", 1);
	f->nprinted += write(1, s, octlenp);
	while (widthp > 0)
	{
		f->nprinted += write(1, " ", 1);
		widthp--;
	}
	return ;
}

void	formatextractionoctal(uintmax_t n, t_struct *f)
{
	int		octlenp;
	int		widthp;
	char	*s;

	s = ft_itoa_base(n, 8);
	octlenp = unsigned_nbr_len(n, 8);
	if (n == 0)
	{
		octlenp = 1;
		if (f->hash == 1)
			octlenp = 0;
		if (f->precisiontf && f->precision == 0)
			octlenp = 0;
	}
	if (f->precisiontf && f->precision > octlenp)
		f->precision = f->precision - octlenp - f->hash;
	else
		f->precision = 0;
	widthp = f->width - (f->precision + octlenp) - f->hash;
	if (f->minus == 0)
		right_aligned_octal(f, widthp, octlenp, s);
	else if (f->minus == 1)
		left_aligned_octal(f, widthp, octlenp, s);
	free(s);
}

void	ifoctal(t_struct *f, va_list ap)
{
	unsigned long n;

	n = 0;
	if (f->length == 0)
		n = va_arg(ap, unsigned int);
	else if (f->length == HH)
		n = (unsigned char)va_arg(ap, unsigned int);
	else if (f->length == H)
		n = (unsigned int)va_arg(ap, unsigned int);
	else if (f->length == LL)
		n = (unsigned long long)va_arg(ap, unsigned long long);
	else if (f->length == L)
		n = (unsigned long)va_arg(ap, unsigned long);
	formatextractionoctal(n, f);
}
