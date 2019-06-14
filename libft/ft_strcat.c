/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:28:08 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 09:02:07 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int strlen;
	int i;

	if (s1)
		strlen = ft_strlen(s1);
	else
		strlen = 0;
	i = 0;
	while (s2[i])
	{
		s1[strlen + i] = s2[i];
		i++;
	}
	s1[strlen + i] = '\0';
	return (s1);
}
