/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:23:17 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 10:26:20 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sclone;

	sclone = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (sclone[i] == (unsigned char)c)
			return ((void *)sclone + i);
		i++;
	}
	return (NULL);
}
