/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:17:38 by yinzhang          #+#    #+#             */
/*   Updated: 2019/05/25 16:17:41 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		signzeroandwidth(t_struct *f, char c, char signc, int sign)
{
	if (f->width > 0 && c == '0')
	{
		if (f->space)
		{
			f->nprinted += write(1, " ", 1);
			f->space = 0;
		}
		if (signc != '\0')
			f->nprinted += write(1, &signc, 1);
		sign -= sign;
	}
	return (sign);
}

void	right_aligned_int(t_struct *f, int intlen, char *s, int sign)
{
	char signc;
	char c;

	if (f->zero && !f->precisiontf)
		c = '0';
	else
		c = ' ';
	signc = '\0';
	if (sign == POSITIVE)
		signc = '+';
	else if (sign == NEGATIVE)
		signc = '-';
	sign = signzeroandwidth(f, c, signc, sign);
	while (f->width-- > 0)
		f->nprinted += write(1, &c, 1);
	if (f->space != 0)
		f->nprinted += write(1, " ", 1);
	if (sign != 0 && signc != '\0')
		f->nprinted += write(1, &signc, 1);
	while (f->precision-- > 0)
		f->nprinted += write(1, "0", 1);
	f->nprinted += write(1, s, intlen);
}

void	left_aligned_int(t_struct *f, int hexlenp, char *s, int sign)
{
	if (f->space)
		f->nprinted += write(1, " ", 1);
	if (sign == POSITIVE)
		f->nprinted += write(1, "+", 1);
	else if (sign == NEGATIVE)
		f->nprinted += write(1, "-", 1);
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
}

void	formatextractionint(intmax_t n, t_struct *f, int sign)
{
	int		intlen;
	char	*s;

	if (f->space && sign != 0)
		f->space = 0;
	s = ft_itoa_base_upper(n, 10);
	intlen = signed_nbr_len(n, 10);
	if (n == 0)
		intlen = 1;
	if (f->precisiontf == 1 && f->precision == 0 && n == 0)
		intlen = 0;
	if (f->precisiontf && f->precision > intlen)
		f->precision = f->precision - intlen;
	else
		f->precision = 0;
	if (sign != 0)
		f->width = f->width - (f->precision + intlen + 1 + f->space);
	else
		f->width = f->width - (f->precision + intlen + f->space);
	if (f->minus == 0)
		right_aligned_int(f, intlen, s, sign);
	if (f->minus == 1)
		left_aligned_int(f, intlen, s, sign);
	free(s);
}

void	ifint(t_struct *f, va_list ap, int sign, intmax_t n)
{
	if (f->length == 0)
		n = (int)va_arg(ap, int);
	else if (f->length == HH)
		n = (signed char)va_arg(ap, int);
	else if (f->length == H)
		n = (short int)va_arg(ap, int);
	else if (f->length == LL)
		n = (long long int)va_arg(ap, long long int);
	else if (f->length == L)
		n = (long int)va_arg(ap, long int);
	if (f->plus && n >= 0)
		sign = POSITIVE;
	else if (n < 0)
	{
		sign = NEGATIVE;
		n = n * -1;
	}
	if (n == LLONG_MIN)
	{
		f->nprinted += write(1, "-9223372036854775808", 20);
		return ;
	}
	formatextractionint(n, f, sign);
}
