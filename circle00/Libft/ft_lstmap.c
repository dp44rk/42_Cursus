/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:38:17 by dpark             #+#    #+#             */
/*   Updated: 2022/04/04 11:54:58 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*i;

	head = NULL;
	if (!lst)
		return (0);
	while (lst)
	{
		i = ft_lstnew(f(lst->content));
		if (!i)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, i);
		lst = lst->next;
	}
	return (head);
}
