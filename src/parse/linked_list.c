/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:59:24 by aben-cha          #+#    #+#             */
/*   Updated: 2024/08/04 14:28:23 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_list	*ft_lstnew(void *content, char c)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content=content;
	ptr->c = c;
	ptr -> next = NULL;
	return (ptr);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
	ptr = *lst;
	if (!ptr)
	{
		*lst = new;
		return ;
	}
	else
	{
		ptr = ft_lstlast(*lst);
		ptr -> next = new;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;
	t_list	*ptr1;

	if (lst == NULL || *lst == NULL)
		return ;
	ptr = *lst;
	while (ptr)
	{
		ptr1 = ptr -> next;
		free(ptr);
		ptr = ptr1;
	}
	*lst = NULL;
}

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*ptr;

	if (!lst)
		return (0);
	len = 0;
	ptr = lst;
	while (ptr)
	{
		len++;
		ptr = ptr -> next;
	}
	return (len);
}
