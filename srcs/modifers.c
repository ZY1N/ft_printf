/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:47:24 by yinzhang          #+#    #+#             */
/*   Updated: 2019/05/16 13:47:27 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags(const char *format, t_struct *f)
{
	while (ft_strchr("-+ #0", format[f->i]))
	{
		if (format[f->i] == '-')
			f->minus = 1;
		if (format[f->i] == '+')
			f->plus = 1;
		if (format[f->i] == ' ')
			f->space = 1;
		if (format[f->i] == '#')
			f->hash = 1;
		if (format[f->i] == '0')
			f->zero = 1;
		f->i++;
	}
	if (f->plus == 1)
		f->space = 0;
}

void	width(const char *format, t_struct *f, va_list ap)
{
	widthstar(format, f, ap);
	if (format[f->i] >= '0' && format[f->i] <= '9')
	{
		f->width = ft_atoi(&format[f->i]);
		while (format[f->i] >= '0' && format[f->i] <= '9')
		{
			f->i++;
			if (format[f->i] == '*')
			{
				if (f->width < 0)
				{
					f->minus = 1;
					f->width = -(f->width);
				}
				while (format[f->i] == '*')
					f->i++;
			}
		}
	}
}

void	precision(const char *format, t_struct *f, va_list ap, int p)
{
	int i;

	i = f->i;
	if (format[i] == '.')
	{
		i++;
		f->precisiontf = 1;
		if (format[i] >= '0' && format[i] <= '9')
		{
			f->precision = ft_atoi(&format[i]);
			while (format[i] >= '0' && format[i] <= '9')
				i++;
		}
		else if (format[f->i] == '*')
		{
			p = va_arg(ap, int);
			if (p >= 0)
				f->precision = p;
			else if (p < 0)
				f->precisiontf = 0;
			while (format[f->i] == '*')
				i++;
		}
	}
	f->i = i;
}

void	length(const char *format, t_struct *f, int i)
{
	i = f->i;
	if (ft_strchr("hlLjz", format[i]))
	{
		if (format[i] == 'h')
		{
			if (format[i + 1] == 'h')
				f->length = HH;
			else if (format[i - 1] != 'h')
				f->length = H;
		}
		if (format[i] == 'l')
		{
			if (format[i + 1] == 'l')
				f->length = LL;
			else if (format[i - 1] != 'l')
				f->length = L;
		}
		if (format[i] == 'L')
			f->length = BIGL;
	}
	while (ft_strchr("hlLjz", format[i]))
		i++;
	f->i = i;
}

void	modifiers(const char *format, t_struct *f, va_list ap)
{
	flags(format, f);
	width(format, f, ap);
	precision(format, f, ap, 0);
	length(format, f, 0);
}
