/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 14:25:47 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/26 10:16:33 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	rotate_b_stack(t_list **b, int to_insert, t_list **instr)
{
	int	rotations;
	int	high;

	rotations = 0;
	high = getextreme(*b, 1);
	if (to_insert > high || to_insert < getextreme(*b, 0))
	{
		while (*b && *((int *)(*b)->content) != high)
		{
			*b = rotate(*b);
			++rotations;
		}
	}
	else
	{
		while (*b && !(*((int *)(*b)->content) < to_insert
			&& *((int *)ft_lstlast(*b)->content) > to_insert))
		{
			*b = rotate(*b);
			++rotations;
		}
	}
	smart_rotate_stack_b(rotations, ft_lstsize(*b), instr);
}

static void	rotate_a_stack_final(t_list **a, int to_push, t_list **instr)
{
	int	rotations;
	int	low;

	rotations = 0;
	low = getextreme(*a, 0);
	if (to_push > getextreme(*a, 1) || to_push < low)
	{
		while (*a && *((int *)(*a)->content) != low)
		{
			*a = rotate(*a);
			++rotations;
		}
	}
	else
	{
		while (*a && !(*((int *)(*a)->content) > to_push
			&& *((int *)ft_lstlast(*a)->content) < to_push))
		{
			*a = rotate(*a);
			++rotations;
		}
	}
	smart_rotate_stack_a(rotations, ft_lstsize(*a), instr);
}

static void	push_cheapest_ab(t_list **a, t_list **b, t_list **instr)
{
	int	cheapest;

	cheapest = get_cheapest_ab(*a, *b);
	move_to_top(a, cheapest, instr, smart_rotate_stack_a);
	rotate_b_stack(b, cheapest, instr);
	push(b, a);
	ft_lstadd_back(instr, ft_lstnew(ft_strdup("pb")));
}

static void	push_cheapest_ba(t_list **a, t_list **b, t_list **instr)
{
	int	cheapest;

	cheapest = get_cheapest_ba(*a, *b);
	move_to_top(b, cheapest, instr, smart_rotate_stack_b);
	rotate_a_stack_final(a, cheapest, instr);
	push(a, b);
	ft_lstadd_back(instr, ft_lstnew(ft_strdup("pa")));
}

void	sort_list(t_list **a, t_list **b, t_list **instr)
{
	int		asize;
	int		bsize;

	asize = ft_lstsize(*a);
	bsize = 0;
	while (asize > 3)
	{
		if (bsize < 2)
		{
			push(b, a);
			ft_lstadd_back(instr, ft_lstnew(ft_strdup("pb")));
			++bsize;
		}
		else
			push_cheapest_ab(a, b, instr);
		--asize;
	}
	if (!issorted(*a))
		sort_three(a, instr);
	while (*b)
	{
		push_cheapest_ba(a, b, instr);
	}
	finalalignment(a, instr);
}
