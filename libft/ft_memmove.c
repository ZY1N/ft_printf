/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:19:38 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 10:27:14 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;
	size_t	i;

	dst1 = (char *)dst;
	src1 = (char *)src;
	i = -1;
	if (src < dst)
	{
		while ((int)--len >= 0)
			*(dst1 + len) = *(src1 + len);
	}
	if (src > dst)
	{
		while (++i < len)
			*(dst1 + i) = *(src1 + i);
	}
	return (dst);
}
