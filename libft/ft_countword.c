/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:15:37 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 22:13:25 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the purpose of this is an offshoot of stringsplit
** it's purpose is to count the number of words
** function skips char c until it hits another char
** after hitting it it adds one to the counter wordcount
** then while the next char is not == to char c then
** it will go to the next char and repeat the loop
*/

int		ft_countword(char *s, char c)
{
	int i;
	int wordcount;

	i = 0;
	wordcount = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			wordcount++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (wordcount);
}
