/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:51:49 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/02 15:36:24 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**This function uses recursionand strjoin to stitch together an answer
** str allocates 2 chars in order to hold broken down digit and a '\0'
**	 * when int is > 10 then it goes into first loop and is broken by the
**	 * strjoin the % is kept at the end for stitching
**	 * * recursion happens and a int / 10 is called
**	 * it happens till int < 10 and is set to char + an '\0'
**	 * after this happens n/10 is no longer true so heap starts collaspping
*/

char		*ft_itoa(int n)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * 2);
	if (!s)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	if (n < 0)
	{
		s[0] = '-';
		s[1] = '\0';
		s = ft_strjoin(s, ft_itoa(-n));
	}
	else if (n >= 10)
		s = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n >= 0 && n < 10)
	{
		s[0] = n + '0';
		s[1] = '\0';
	}
	return (s);
}
