/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_cheapest_ba.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 12:36:39 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/26 10:18:18 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	smart_rotate_stack_a(int rotations, int size, t_list **instr)
{
	if (rotations > size / 2)
	{
		rotations = size - rotations;
		while (rotations > 0)
		{
			ft_lstadd_back(instr, ft_lstnew(ft_strdup("rra")));
			--rotations;
		}
	}
	while (rotations > 0)
	{
		ft_lstadd_back(instr, ft_lstnew(ft_strdup("ra")));
		--rotations;
	}
}

static void	smart_rotate_a(t_list *a, int current, int size, t_list **instr)
{
	int	rotations;
	int	low;

	rotations = 0;
	low = getextreme(a, 0);
	if (current > getextreme(a, 1) || current < low)
	{
		while (a && *((int *)a->content) != low)
		{
			++rotations;
			a = a->next;
		}
	}
	else
	{
		while (a && !(*((int *)a->content) > current
				&& *((int *)ft_lstlast(a)->content) < current))
		{
			++rotations;
			a = a->next;
		}
	}
	smart_rotate_stack_a(rotations, size, instr);
}

static int	get_instr(t_list *a, t_list *b, int index, t_list **instr)
{
	int	current;

	current = getcurrent(b, index);
	smart_rotate_stack_b(index, ft_lstsize(b), instr);
	smart_rotate_a(a, current, ft_lstsize(a), instr);
	ft_lstadd_back(instr, ft_lstnew(ft_strdup("pa")));
	optimise_instr(*instr);
	return (current);
}

int	get_cheapest_ba(t_list *a, t_list *b)
{
	int		current;
	int		cheapest;
	int		numberofinstr;
	int		index;
	t_list	*instr;

	numberofinstr = 0;
	index = 0;
	instr = NULL;
	while (index < ft_lstsize(b))
	{
		current = get_instr(a, b, index, &instr);
		if (ft_lstsize(instr) < numberofinstr || numberofinstr == 0)
		{
			numberofinstr = ft_lstsize(instr);
			cheapest = current;
		}
		ft_lstclear(&instr, del);
		if (numberofinstr == 1)
			break ;
		++index;
	}
	return (cheapest);
}
