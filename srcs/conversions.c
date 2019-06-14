/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:38:55 by yinzhang          #+#    #+#             */
/*   Updated: 2019/05/16 13:38:57 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversions(char c, va_list ap, t_struct *f)
{
	if (c == 'c')
		ifchar(f, ap);
	else if (c == 's')
		ifstring(f, ap);
	else if (c == 'p')
		ifpointer(f, ap, 2);
	else if (c == 'd' || c == 'i')
		ifint(f, ap, 0, 0);
	else if (c == 'o')
		ifoctal(f, ap);
	else if (c == 'u')
		ifudecint(f, ap);
	else if (c == 'x' || c == 'X')
		ifhex(f, ap, c);
	else if (c == 'f')
		ifloat(f, ap);
	else if (c == '%')
		ifpercent(f);
	else if (c == 'y')
		ifcat();
	else if (c == 'b')
		ifbinary(f, ap);
}
