/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:02:23 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 10:27:28 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total;
	char	*dstclone;

	dstclone = dst;
	total = ft_strlen(src);
	while (*dstclone != '\0' && dstsize > 0)
	{
		dstsize--;
		total++;
		dstclone++;
	}
	if (dstsize == 0)
		return (total);
	while (dstsize > 1)
	{
		*dstclone = *src;
		dstclone++;
		src++;
		dstsize--;
	}
	*dstclone = '\0';
	return (total);
}
