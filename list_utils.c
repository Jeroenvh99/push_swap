/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:13:54 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/26 10:15:25 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"push_swap.h"

void	printlist_instr(t_list *head)
{
	while (head)
	{
		ft_printf("%s\n", (char *)head->content);
		head = head->next;
	}
}

int	lstsearch(t_list *lst, int *num)
{
	while (lst)
	{
		if (*((int *)lst->content) == *num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	del(void *node)
{
	free(node);
	node = NULL;
}

int	issorted(t_list *lst)
{
	int	prevnum;

	while (lst)
	{
		if (lst->prev && *((int *)lst->content) < prevnum)
			return (0);
		prevnum = *((int *)lst->content);
		lst = lst->next;
	}
	return (1);
}

//1 = high, 0 = low
int	getextreme(t_list *lst, int high_or_low)
{
	int	current;
	int	res;

	while (lst)
	{
		current = *(int *)(lst->content);
		if (!lst->prev || (high_or_low == 0 && current < res)
			|| (high_or_low == 1 && current > res))
			res = current;
		lst = lst->next;
	}
	return (res);
}
