/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimise_instr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 17:03:47 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/26 15:49:53 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static t_list	*find_instr_pair(t_list *current, char *instr, char *pair,
	int size)
{
	t_list	*temp;

	temp = NULL;
	if (ft_strncmp((char *)current->content, instr, size) == 0)
	{
		temp = current->next;
		while (temp && ft_strncmp((char *)temp->content, pair, size) != 0)
		{
			if (ft_strncmp((char *)temp->content, instr, size) != 0
				|| ft_strncmp((char *)temp->content, "pa", 2) != 0
				|| ft_strncmp((char *)temp->content, "pb", 2) != 0)
			{
				temp = NULL;
				break ;
			}
			temp = temp->next;
		}
		if (temp)
			((char *)(current->content))[size - 1] = 'r';
	}
	return (temp);
} 

void	optimise_instr(t_list *lst)
{
	t_list	*temp;

	while (lst && lst->next)
	{
		temp = find_instr_pair(lst, "ra", "rb", 2);
		if (!temp)
			temp = find_instr_pair(lst, "rb", "ra", 2);
		if (!temp)
			temp = find_instr_pair(lst, "rra", "rrb", 3);
		if (!temp)
			temp = find_instr_pair(lst, "rrb", "rra", 3);
		if (temp)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			ft_lstdelone(temp, del);
		}
		lst = lst->next;
	}
}
