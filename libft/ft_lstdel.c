/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:16:05 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 21:17:20 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** recursively calls itself and applies del function all all of them
** each time it deletes the current one starting with the last one
** when next is '\0'
** starts deleting the last link and collasping
*/

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst == NULL)
		return ;
	ft_lstdel(&(*alst)->next, del);
	ft_lstdelone(alst, del);
}
