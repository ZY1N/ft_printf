/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:13:18 by yinzhang          #+#    #+#             */
/*   Updated: 2019/02/27 10:50:31 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t lenofneedle;

	lenofneedle = ft_strlen((char *)needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (ft_strncmp(haystack, needle, lenofneedle) == 0)
		{
			return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
