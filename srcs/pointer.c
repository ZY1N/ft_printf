/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 19:45:33 by yinzhang          #+#    #+#             */
/*   Updated: 2019/05/24 19:46:42 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hex_count(unsigned long long n)
{
	int i;

	i = 0;
	while (n / 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int		rightaligned(int widthp, int precisionp, int hexlenp, char *s)
{
	int i;

	i = 0;
	while (widthp > 0)
	{
		i += write(1, " ", 1);
		widthp--;
	}
	i += write(1, "0x", 2);
	while (precisionp > 0)
	{
		i += write(1, "0", 1);
		precisionp--;
	}
	i += write(1, s, hexlenp);
	return (i);
}

int		leftaligned(int widthp, int precisionp, int hexlenp, char *s)
{
	int i;

	i = 0;
	i += write(1, "0x", 2);
	while (precisionp > 0)
	{
		i += write(1, "0", 1);
		precisionp--;
	}
	i += write(1, s, hexlenp);
	while (widthp > 0)
	{
		i += write(1, " ", 1);
		widthp--;
	}
	return (i);
}

void	ifpointer(t_struct *f, va_list ap, int oxheading)
{
	int					hexlenp;
	char				*s;
	int					precisionp;
	int					widthp;
	unsigned long long	pointer;

	pointer = (unsigned long long)va_arg(ap, void *);
	oxheading = 2;
	hexlenp = hex_count(pointer) + 1;
	s = ft_itoa_base(pointer, 16);
	precisionp = f->precision - hexlenp;
	widthp = f->width - hexlenp - oxheading;
	if (f->precisiontf && f->precision == 0)
		hexlenp = 0;
	if (f->minus)
		f->nprinted += leftaligned(widthp, precisionp, hexlenp, s);
	else
		f->nprinted += rightaligned(widthp, precisionp, hexlenp, s);
	free(s);
}
