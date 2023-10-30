/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:17:57 by dpark             #+#    #+#             */
/*   Updated: 2022/04/04 22:28:10 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **head, void (*del)(void *))
{
	t_list	*cur;
	t_list	*temp;

	cur = *head;
	while (cur != NULL)
	{
		temp = (cur)->next;
		del((cur)->content);
		free(cur);
		cur = temp;
	}
	*head = 0;
}
