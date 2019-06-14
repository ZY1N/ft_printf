/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 12:50:37 by yinzhang          #+#    #+#             */
/*   Updated: 2019/02/27 21:23:49 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *x;

	x = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (x == NULL)
		return (NULL);
	ft_strcpy(x, src);
	return (x);
}
