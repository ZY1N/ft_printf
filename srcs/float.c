/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 19:53:58 by yinzhang          #+#    #+#             */
/*   Updated: 2019/06/03 14:22:03 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		power(intmax_t n, int i)
{
	long		k;
	long double	res;

	res = n;
	k = 0;
	if (i == 0)
		return (1);
	while (k < i - 1)
	{
		res = res * n;
		k++;
	}
	return (res);
}

t_fstruct		formatextractionf3(t_fstruct g, t_struct *f)
{
	if (g.fl == 0)
		g.zeros--;
	g.hash = 0;
	if (f->hash)
		g.hash = 1;
	if (f->hash && ft_strlen(g.s2) > 0)
		g.hash = 0;
	g.dot = 0;
	if ((ft_strlen(g.s2) > 0 && g.precision != 0) || f->hash)
		g.dot = 1;
	if (g.precision != 0)
		g.padding = f->width - f->precision - g.beforedecimalnbr
		- g.hash - g.signint - g.dot;
	else
		g.padding = f->width - f->precision - g.beforedecimalnbr
		- g.hash - g.signint - g.dot - 1;
	g.zeros = g.zeros - g.precisionaddon;
	if (f->minus == 0)
		rightalignedf(f, g);
	else if (f->minus == 1)
		leftalignedf(f, g);
	return (g);
}

t_fstruct		formatextractionf2(t_fstruct g, t_struct *f, long double n)
{
	if (f->precisiontf == 1 && f->precision >= 0)
		g.precision = f->precision;
	g.i = (long long)n;
	g.s1 = ft_itoa_base(g.i, 10);
	n = n - (long double)g.i;
	g.precisionaddon = 0;
	if (n == 0)
		g.precisionaddon = g.precision - 1;
	n = (n * power(10, g.precision));
	g.fl = (n >= 0) ? (long)(n + 0.5) : (long)(n - 0.5);
	if (g.fl == power(10, g.precision) && g.fl != 0)
	{
		g.s1 = ft_itoa_base(g.i + 1, 10);
		g.fl = 0;
		if (g.fl == 0)
			g.precisionaddon = g.precision - 1;
	}
	g.s2 = ft_itoa_base(g.fl, 10);
	if (g.precision != 0)
		g.zeros = g.precision - signed_nbr_len(g.fl, 10);
	else
		g.zeros = 0;
	g.beforedecimalnbr = signed_nbr_len(n, 10);
	return (g);
}

void			formatextractionf(long double n, t_struct *f)
{
	t_fstruct	g;

	g.signint = 0;
	if (f->plus)
		g.signint = 1;
	g.sign = ' ';
	if (n < 0)
	{
		g.sign = '-';
		n = -n;
		g.signint = 1;
	}
	else if (n > 0 && f->plus)
		g.sign = '+';
	g.precision = 6;
	if (f->zero == 1)
		g.c = '0';
	else
		g.c = ' ';
	if (f->minus)
		g.c = ' ';
	g = formatextractionf2(g, f, n);
	g = formatextractionf3(g, f);
	free(g.s1);
	free(g.s2);
}

void			ifloat(t_struct *f, va_list ap)
{
	long double n;

	n = 0;
	if (f->length == 0)
		n = (long double)va_arg(ap, double);
	else if (f->length == BIGL)
		n = (long double)va_arg(ap, long double);
	formatextractionf(n, f);
}
