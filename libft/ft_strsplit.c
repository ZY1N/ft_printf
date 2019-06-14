/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:24:18 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 23:39:36 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countword(char const *str, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			len++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		a;
	int		b;
	int		d;
	char	**s2;

	if (!s || !c)
		return (NULL);
	if (!(s2 = (char **)malloc(sizeof(*s2) * (countword(s, c) + 1))))
		return (NULL);
	a = 0;
	b = 0;
	while (a < countword(s, c))
	{
		d = 0;
		if (!(s2[a] = ft_strnew(countword(&s[b], c))))
			s2[a] = NULL;
		while (s[b] == c)
			b++;
		while (s[b] != c && s[b])
			s2[a][d++] = s[b++];
		s2[a][d] = '\0';
		a++;
	}
	s2[a] = 0;
	return (s2);
}
