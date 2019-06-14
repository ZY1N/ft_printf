/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:15:37 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 09:31:59 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *found;
	const char *p;

	c = (unsigned char)c;
	if (c == '\0')
		return (ft_strchr(s, '\0'));
	found = NULL;
	while ((p = ft_strchr(s, c)) != NULL)
	{
		found = p;
		s = p + 1;
	}
	return ((char *)found);
}
