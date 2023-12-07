/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_list_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 19:36:49 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/25 19:37:20 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	move_to_top(t_list **a, int to_push, t_list **instr,
	void (*smart_rotate)(int, int, t_list**))
{
	int	rotations;

	rotations = 0;
	while (*a && *((int *)(*a)->content) != to_push)
	{
		*a = rotate(*a);
		++rotations;
	}
	smart_rotate(rotations, ft_lstsize(*a), instr);
}

void	finalalignment(t_list **a, t_list **instr)
{
	int	rotations;

	rotations = 0;
	while (!issorted(*a))
	{
		*a = rotate(*a);
		++rotations;
	}
	smart_rotate_stack_a(rotations, ft_lstsize(*a), instr);
}
