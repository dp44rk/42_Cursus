/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:07:34 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:30:08 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*ft_lstnew(int cmd)
{
	t_cmd	*ret;

	ret = ft_calloc(1, sizeof(t_cmd));
	if (ret == NULL)
		return (NULL);
	ret->cmd = cmd;
	return (ret);
}

t_cmd	*ft_lstlast(t_cmd *head)
{
	t_cmd	*cur;

	if (head == NULL)
		return (NULL);
	cur = head;
	while (cur->next)
		cur = cur->next;
	return (cur);
}

void	ft_lstclear(t_cmd **head)
{
	t_cmd	*cur;
	t_cmd	*temp;

	cur = *head;
	while (cur)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	*head = 0;
}

void	ft_lst_delone(t_cmd **head, t_cmd *deleted)
{
	t_cmd	*cur;

	if (*head == deleted)
	{
		free(deleted);
		*head = NULL;
		return ;
	}
	cur = *head;
	while (cur->next)
	{
		if (cur->next == deleted)
		{
			cur->next = deleted->next;
			free(deleted);
			return ;
		}
		cur = cur->next;
	}
}
