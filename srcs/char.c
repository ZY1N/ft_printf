/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:38:52 by yinzhang          #+#    #+#             */
/*   Updated: 2019/06/09 13:16:32 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ifpercent(t_struct *f)
{
	int	num;

	if (f->width != 0 && f->minus == 0)
	{
		num = f->width - 1;
		if (f->zero != 0)
			writezeros(num);
		else
			writeblanks(num);
		write(1, "%", 1);
		f->nprinted = f->nprinted + num + 1;
	}
	else if (f->width && f->minus == 1)
	{
		num = f->width - 1;
		write(1, "%", 1);
		writeblanks(num);
		f->nprinted = f->nprinted + num + 1;
	}
	else
	{
		write(1, "%", 1);
		f->nprinted++;
	}
}

void	ifchar(t_struct *f, va_list ap)
{
	int				num;
	unsigned char	c;

	num = 0;
	c = (unsigned char)va_arg(ap, int);
	if (f->width && f->minus == 0)
	{
		num = f->width - 1;
		if (f->zero != 0)
			writezeros(num);
		else if (f->zero == 0)
			writeblanks(num);
		write(1, &c, 1);
		f->nprinted = f->nprinted + num;
	}
	else if (f->width && f->minus == 1)
	{
		num = f->width - 1;
		write(1, &c, 1);
		writeblanks(num);
		f->nprinted = f->nprinted + num;
	}
	else
		write(1, &c, 1);
	f->nprinted++;
}
