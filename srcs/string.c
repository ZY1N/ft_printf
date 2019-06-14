/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:50:27 by yinzhang          #+#    #+#             */
/*   Updated: 2019/05/24 13:50:29 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rightalignedchar(t_struct *f, char c, char *s, int i)
{
	if (f->minus != 0)
	{
		c = ' ';
		if (f->precisiontf && i > f->precision)
			i = f->precision;
		f->len = f->len + write(1, s, i);
		f->nprinted = f->nprinted + i;
		while (f->width > i)
		{
			f->len = f->len + write(1, &c, 1);
			f->nprinted++;
			f->width--;
		}
	}
}

void	leftalignedchar(t_struct *f, char c, char *s, int i)
{
	if (f->minus == 0)
	{
		if (f->precisiontf && i > f->precision)
			i = f->precision;
		if (f->width > i)
		{
			while ((f->width - i) > 0)
			{
				f->len = f->len + write(1, &c, 1);
				f->nprinted++;
				f->width--;
			}
		}
		f->len = f->len + write(1, s, i);
		f->nprinted = f->nprinted + i;
	}
}

void	ifnull(void *s, t_struct *f)
{
	if (s == NULL)
	{
		f->nprinted += write(1, "(null)", 6);
		f->minus = 3;
	}
}

void	charhandler(t_struct *f, va_list ap)
{
	char	*s;
	int		i;
	char	c;

	if (f->zero == 1)
		c = '0';
	else
		c = ' ';
	s = (char *)va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	i = ft_strlen(s);
	if (f->minus == 1)
		rightalignedchar(f, c, s, i);
	else if (f->minus == 0)
		leftalignedchar(f, c, s, i);
}

void	ifstring(t_struct *f, va_list ap)
{
	charhandler(f, ap);
}
