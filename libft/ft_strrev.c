/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:26:34 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 22:14:24 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		length;
	char	buffer;

	length = 0;
	while (s[length])
		length++;
	i = 0;
	while (++i < length--)
	{
		buffer = s[i];
		s[i] = s[length];
		s[length] = buffer;
	}
	s[i] = '\0';
	return (s);
}
