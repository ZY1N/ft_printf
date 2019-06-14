/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:23:43 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 22:10:52 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the purpose of this function is to return the length of a word
** that is at whichword. aka which word of a string you wanted to seperate
** first we skip chars (could be tabs, spaces, whatever)
*/

int	ft_wordlen(char const *s, char c)
{
	int i;
	int length;

	i = 0;
	length = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		length++;
	}
	return (length);
}
