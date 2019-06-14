/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:42:59 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 21:45:48 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this function allocates, and returns a fresh list
** content will be put into new link with content size
**
** first makes a new varable for linkedlist
** then if it fails exit the program
** else if will go on and mallot enough space for the content and move
**
** if the allocation fails return null
** otherwise move the content into newlist-> content && the size
** set the next one to NULL
*/

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(t_list) * 1);
	if (newlist == NULL)
		return (NULL);
	if (content == NULL)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		newlist->content = (t_list *)malloc(content_size);
		if (newlist->content == NULL)
			return (NULL);
		ft_memmove(newlist->content, content, content_size);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}
