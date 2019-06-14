/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:48:42 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 23:34:15 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	size_t			len;
	char			*new;
	char			*tar;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	tar = new;
	index = 0;
	while (*s != '\0')
	{
		*tar = f(index, *s);
		tar++;
		s++;
		index++;
	}
	*tar = '\0';
	return (new);
}
