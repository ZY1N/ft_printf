/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:18:22 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 19:07:53 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int n)
{
	char	*x;
	int		difference;

	difference = ft_strlen(src) - n;
	x = (char *)malloc(sizeof(char) * (ft_strlen(src) - difference + 1));
	if (x == NULL)
		return (NULL);
	ft_strncpy(x, src, n);
	return (x);
}
