/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:05:54 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 21:45:22 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this function we take address of a pointer in chain and a function
** we will be be applying funciton del to it
** which frees the content of memory
**
** del deletes the content, so then we free the memory for alst
** set the link equal to NULL
*/

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
