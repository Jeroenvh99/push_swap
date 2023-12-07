/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_cheapest_ab.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 12:36:39 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/26 10:19:02 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	smart_rotate_stack_b(int rotations, int size, t_list **instr)
{
	if (rotations > size / 2)
	{
		rotations = size - rotations;
		while (rotations > 0)
		{
			ft_lstadd_back(instr, ft_lstnew(ft_strdup("rrb")));
			--rotations;
		}
	}
	while (rotations > 0)
	{
		ft_lstadd_back(instr, ft_lstnew(ft_strdup("rb")));
		--rotations;
	}
}

static void	smart_rotate_b(t_list *b, int current, int size, t_list **instr)
{
	int	rotations;
	int	high;

	rotations = 0;
	high = getextreme(b, 1);
	if (current > high || current < getextreme(b, 0))
	{
		while (b && *((int *)b->content) != high)
		{
			++rotations;
			b = b->next;
		}
	}
	else
	{
		while (b && !(*((int *)b->content) < current
				&& *((int *)ft_lstlast(b)->content) > current))
		{
			++rotations;
			b = b->next;
		}
	}
	smart_rotate_stack_b(rotations, size, instr);
}

int	getcurrent(t_list *lst, int i)
{
	t_list	*current;

	current = lst;
	while (i > 0)
	{
		current = current->next;
		--i;
	}
	return (*((int *)current->content));
}

static int	get_instr(t_list *a, t_list *b, int index, t_list **instr)
{
	int	current;

	current = getcurrent(a, index);
	smart_rotate_stack_a(index, ft_lstsize(a), instr);
	smart_rotate_b(b, current, ft_lstsize(b), instr);
	ft_lstadd_back(instr, ft_lstnew(ft_strdup("pb")));
	optimise_instr(*instr);
	return (current);
}

int	get_cheapest_ab(t_list *a, t_list *b)
{
	int		current;
	int		cheapest;
	int		numberofinstr;
	int		index;
	t_list	*instr;

	numberofinstr = 0;
	index = 0;
	instr = NULL;
	while (index < ft_lstsize(a))
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
