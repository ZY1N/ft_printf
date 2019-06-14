/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 20:31:42 by yinzhang          #+#    #+#             */
/*   Updated: 2019/06/06 20:31:43 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	right_aligned_binary(t_struct *f, int widthp, int binarylenp, char *s)
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
	f->nprinted += write(1, s, binarylenp);
}

void	left_aligned_binary(t_struct *f, int widthp, int binarylenp, char *s)
{
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	if (f->hash == 1)
		f->nprinted += write(1, "0", 1);
	f->nprinted += write(1, s, binarylenp);
	while (widthp > 0)
	{
		f->nprinted += write(1, " ", 1);
		widthp--;
	}
	return ;
}

void	formatextractionbinary(uintmax_t n, t_struct *f)
{
	int		binarylenp;
	int		widthp;
	char	*s;

	s = ft_itoa_base(n, 2);
	binarylenp = unsigned_nbr_len(n, 2);
	if (n == 0)
	{
		binarylenp = 1;
		if (f->hash == 1)
			binarylenp = 0;
		if (f->precisiontf && f->precision == 0)
			binarylenp = 0;
	}
	if (f->precisiontf && f->precision > binarylenp)
		f->precision = f->precision - binarylenp - f->hash;
	else
		f->precision = 0;
	widthp = f->width - (f->precision + binarylenp) - f->hash;
	if (f->minus == 0)
		right_aligned_binary(f, widthp, binarylenp, s);
	else if (f->minus == 1)
		left_aligned_binary(f, widthp, binarylenp, s);
	free(s);
}

void	ifbinary(t_struct *f, va_list ap)
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
	formatextractionbinary(n, f);
}
