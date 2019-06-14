/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:25:36 by yinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 23:41:58 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this function applies function f to every one of the links on lst
** first if is null return null
** otherswise recrusively call next and collaspe the stack
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = f(lst);
	if (lst != NULL || f != NULL)
	{
		new = f(lst);
		if (new != NULL && lst->next != NULL)
			new->next = ft_lstmap(lst->next, f);
		return (new);
	}
	return (NULL);
}
