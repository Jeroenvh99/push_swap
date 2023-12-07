/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:13:15 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/19 12:15:44 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./libft/libft.h"

t_list	*swap(t_list *lst)
{
	t_list	*newhead;

	if (!(lst && lst->next))
		return (NULL);
	newhead = lst->next;
	lst->next = lst->next->next;
	if (lst->next)
		lst->next->prev = lst;
	newhead->prev = NULL;
	newhead->next = lst;
	lst->prev = newhead;
	return (newhead);
}

void	push(t_list **lst1, t_list **lst2)
{
	t_list	*current;

	if (!*lst2)
		return ;
	current = *lst2;
	if (current->next)
	{
		current->next->prev = NULL;
		*lst2 = current->next;
	}
	else
		*lst2 = NULL;
	if (*lst1)
	{
		(*lst1)->prev = current;
		current->next = *lst1;
	}
	else
		current->next = NULL;
	*lst1 = current;
}

t_list	*rotate(t_list *lst)
{
	t_list	*temp;
	t_list	*newhead;

	if (!(lst && lst->next))
		return (NULL);
	temp = lst;
	newhead = lst->next;
	lst = lst->next;
	temp->next = NULL;
	lst->prev = NULL;
	while (lst->next)
		lst = lst->next;
	temp->prev = lst;
	lst->next = temp;
	return (newhead);
}

t_list	*rrotate(t_list *lst)
{
	t_list	*current;
	t_list	*newhead;

	if (!(lst && lst->next))
		return (NULL);
	current = lst;
	while (current->next)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	lst->prev = current;
	current->next = lst;
	newhead = current;
	return (newhead);
}
