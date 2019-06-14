/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:04:20 by yinzhang          #+#    #+#             */
/*   Updated: 2019/06/06 18:57:20 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	bezerostruct(t_struct *list)
{
	list->i = 0;
	list->nprinted = 0;
	list->len = 0;
	list->minus = 0;
	list->plus = 0;
	list->space = 0;
	list->zero = 0;
	list->hash = 0;
	list->width = 0;
	list->precisiontf = 0;
	list->precision = 0;
	list->length = 0;
}

void	bezerostruct2(t_struct *list)
{
	list->len = 0;
	list->minus = 0;
	list->plus = 0;
	list->space = 0;
	list->zero = 0;
	list->hash = 0;
	list->width = 0;
	list->precisiontf = 0;
	list->precision = 0;
	list->length = 0;
}

int		parsel2(t_struct *f, int position, const char *format, va_list ap)
{
	f->i = position;
	if (!ft_strchr("cspdiouxXfyb%", format[position]))
		modifiers(format, f, ap);
	else if (ft_strchr(("cspdiouxXfyb%"), format[position]))
	{
		conversions(format[position], ap, f);
		bezerostruct2(f);
	}
	return (f->i - 1);
}

int		formatparse(const char *format, t_struct *list, va_list ap, int pos)
{
	while (format[pos] != '\0')
	{
		if (format[pos] != '%' && format[pos])
			list->nprinted += write(1, &format[pos], 1);
		else if (format[pos] == '%')
		{
			if (!ft_strchr(ALLSYMBOLS, format[pos + 1]))
				break ;
			while (ft_strchr(ALLSYMBOLS, format[pos + 1]))
			{
				pos = pos + 1;
				if (ft_strchr("cspdiouxXfyb%", format[pos]))
				{
					pos = parsel2(list, pos, format, ap) + 2;
					break ;
				}
				else
					pos = parsel2(list, pos, format, ap);
			}
			continue;
		}
		pos++;
	}
	return (list->nprinted);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			status;
	t_struct	*s;
	int			formatlen;

	formatlen = ft_strlen(format);
	if (!(s = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	bezerostruct(s);
	s->format = (char *)format;
	va_start(ap, format);
	if (!format[0])
	{
		error();
		return (0);
	}
	if (formatlen == 1 && format[0] == '%')
		return (0);
	else
		status = formatparse(format, s, ap, 0);
	va_end(ap);
	free(s);
	return (status);
}
