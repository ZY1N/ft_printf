/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:38:24 by yinzhang          #+#    #+#             */
/*   Updated: 2019/06/06 14:38:26 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rightalignedf3(t_struct *f, t_fstruct g)
{
	if (g.dot == 1 || f->hash)
		f->nprinted += write(1, ".", 1);
	while (g.zeros > 0 && g.precision != 0)
	{
		f->nprinted += write(1, "0", 1);
		g.zeros--;
		g.precision--;
	}
	while (*g.s2 && g.precision != 0)
	{
		f->nprinted += write(1, g.s2, 1);
		g.s2++;
		g.precision--;
	}
	while (g.precisionaddon-- > 0)
		f->nprinted += write(1, "0", 1);
}

void	rightalignedf2(t_struct *f, t_fstruct g, char space)
{
	if (f->precision == 0 && f->precisiontf == 1)
		space = ' ';
	if (f->precision == 0 && f->zero == 0 && f->width != 0)
		space = ' ';
	if (f->space == 1)
	{
		f->nprinted += write(1, &space, 1);
		g.padding--;
	}
	while (g.padding-- > 0)
		f->nprinted += write(1, &g.c, 1);
	if (g.sign != 'a' && g.signint)
	{
		if (g.signint == 1 && g.sign)
			f->nprinted += write(1, &g.sign, 1);
	}
	while (*g.s1)
	{
		f->nprinted += write(1, g.s1, 1);
		g.s1++;
	}
}

void	rightalignedf(t_struct *f, t_fstruct g)
{
	char space;

	space = '0';
	if (g.padding > 0 && g.c == '0')
	{
		if (g.signint == 1 && g.sign)
		{
			f->nprinted += write(1, &g.sign, 1);
			g.sign = 'a';
			f->space = 0;
		}
	}
	if (f->space == 1 && (f->zero == 0 || f->precision))
		space = ' ';
	if (g.sign == '-' || f->precision == 0)
	{
		if (f->precision == 0 && f->space)
			f->space = 1;
		else
			f->space = 0;
	}
	rightalignedf2(f, g, space);
	rightalignedf3(f, g);
}

void	leftalignedf2(t_struct *f, t_fstruct g)
{
	while (*g.s2 && g.precision != 0)
	{
		f->nprinted += write(1, g.s2, 1);
		g.s2++;
		g.precision--;
	}
	if (f->space && g.sign == '-' && g.precision > 0)
	{
		f->nprinted += write(1, " ", 1);
		g.padding--;
		f->space = 0;
	}
	while (g.precisionaddon-- > 0)
		f->nprinted += write(1, "0", 1);
	while (g.padding-- > 0)
		f->nprinted += write(1, &g.c, 1);
}

void	leftalignedf(t_struct *f, t_fstruct g)
{
	if (f->space && g.sign != '-')
	{
		f->nprinted += write(1, " ", 1);
		g.padding--;
		f->space = 0;
	}
	if (g.signint == 1 && g.sign)
		f->nprinted += write(1, &g.sign, 1);
	while (*g.s1)
	{
		f->nprinted += write(1, g.s1, 1);
		g.s1++;
	}
	if (g.dot == 1 || f->hash)
		f->nprinted += write(1, ".", 1);
	while (g.zeros-- > 0 && g.precision-- != 0)
		f->nprinted += write(1, "0", 1);
	leftalignedf2(f, g);
}
