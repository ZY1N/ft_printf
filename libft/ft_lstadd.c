/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:20:02 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 21:20:08 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this adds another link to the list
** new is passed in as a variable
** the next link to it is set as the address of alst
** so it adds it in fornot of it
*/

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}
