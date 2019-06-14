/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxilliary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:52:01 by yinzhang          #+#    #+#             */
/*   Updated: 2019/05/24 13:52:06 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	writeblanks(int n)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
}

void	writezeros(int n)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
}

int		unsigned_nbr_len(uintmax_t n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char	*ft_stradd(char *a, char *b)
{
	char	*temp;

	if (a != NULL && b != NULL)
	{
		temp = ft_strjoin(a, b);
		free(a);
		free(b);
	}
	else
	{
		if (a == NULL)
			temp = b;
		else
			temp = a;
	}
	return (temp);
}

void	error(void)
{
	write(1, "", 0);
}
