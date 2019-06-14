/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:11:45 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 10:24:18 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*shadowclones1;
	unsigned char	*shadowclones2;
	size_t			i;

	shadowclones1 = (unsigned char *)s1;
	shadowclones2 = (unsigned char *)s2;
	i = 0;
	while (n > i)
	{
		if (shadowclones1[i] == shadowclones2[i])
			i++;
		else if (shadowclones1[i] != shadowclones2[i])
		{
			return (shadowclones1[i] - shadowclones2[i]);
			i++;
		}
	}
	return (0);
}
