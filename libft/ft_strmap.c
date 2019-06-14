/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:48:49 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 23:33:26 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tar;
	size_t	len;
	char	*new;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == '\0')
		return (NULL);
	tar = new;
	while (*s != '\0')
	{
		*tar = f(*s);
		tar++;
		s++;
	}
	*tar = '\0';
	return (new);
}
