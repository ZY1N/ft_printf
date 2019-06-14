/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 09:39:22 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 23:39:11 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty(void)
{
	char		*string;

	string = (char *)malloc(sizeof(char));
	if (string != NULL)
		*string = '\0';
	return (string);
}

char		*ft_strtrim(char const *s)
{
	char const	*start;
	char		*new;

	if (!s)
		return (NULL);
	while (*s != '\0' && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	if (*s == '\0')
		return (empty());
	start = s;
	while (*s != '\0')
		s++;
	s--;
	while (s != start && (*s == ' ' || *s == '\n' || *s == '\t'))
		s--;
	new = (char *)malloc(sizeof(char) * (unsigned long)(s - start + 2));
	if (new == NULL)
		return (NULL);
	new[s - start + 1] = '\0';
	ft_strncpy(new, start, (size_t)(s - start + 1));
	return (new);
}
