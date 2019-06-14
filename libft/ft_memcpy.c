/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:30:15 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 09:19:34 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dstcpy;
	unsigned char *srccpy;

	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	while (n > 0)
	{
		*dstcpy++ = *srccpy++;
		n--;
	}
	return (dst);
}
