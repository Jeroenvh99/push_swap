/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 11:32:26 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/26 10:17:30 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	sort_low_up(t_list **a, t_list **instr)
{
	*a = rrotate(*a);
	ft_lstadd_back(instr, ft_lstnew(ft_strdup("rra")));
	*a = swap(*a);
	ft_lstadd_back(instr, ft_lstnew(ft_strdup("sa")));
}

static void	sort_high_up(t_list **a, t_list **instr)
{
	*a = rotate(*a);
	ft_lstadd_back(instr, ft_lstnew(ft_strdup("ra")));
	if (!issorted(*a))
	{
		*a = swap(*a);
		ft_lstadd_back(instr, ft_lstnew(ft_strdup("sa")));
	}
}

void	sort_three(t_list **a, t_list **instr)
{
	if (getextreme(*a, 0) == *(int *)((*a)->content))
	{
		sort_low_up(a, instr);
	}
	else if (getextreme(*a, 1) == *(int *)((*a)->content))
	{
		sort_high_up(a, instr);
	}
	else
	{
		if (*(int *)((*a)->next->content) == getextreme(*a, 1))
		{
			*a = rrotate(*a);
			ft_lstadd_back(instr, ft_lstnew(ft_strdup("rra")));
		}
		else
		{
			*a = swap(*a);
			ft_lstadd_back(instr, ft_lstnew(ft_strdup("sa")));
		}
	}
}
