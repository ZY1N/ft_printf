/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:01:15 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 10:29:24 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;
	int		i;
	char	*s1buff;

	len = ft_strlen((const char *)s1);
	s1buff = s1;
	i = 0;
	while (n > 0 && s2[i] != '\0')
	{
		s1buff[len] = s2[i];
		len++;
		i++;
		n--;
	}
	s1buff[len] = '\0';
	return (s1);
}
