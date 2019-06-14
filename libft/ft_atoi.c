/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:11:47 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/02 15:16:44 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		ans;
	int		len;

	ans = 0;
	sign = 1;
	len = 0;
	while (*str && (*str == '\t' || *str == '\f' || *str == '\r'
				|| *str == '\n' || *str == '\v' || *str == ' '))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? str++ : str;
	while (ft_isdigit(str[len]))
		len++;
	if (len > 19)
		return ((sign > 0) ? -1 : 0);
	while (*str && *str >= 48 && *str <= 57)
		ans = ans * 10 + (*str++ - '0');
	return (sign * ans);
}
