/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 20:01:20 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/04 11:07:14 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	lenofneedle;

	lenofneedle = ft_strlen(needle);
	if (needle == '\0')
		return ((char *)hay);
	while (*hay != '\0' && len >= lenofneedle)
	{
		if (ft_strncmp(hay, needle, lenofneedle) == 0)
			return ((char *)hay);
		len--;
		hay++;
	}
	return (NULL);
}
