/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:14:09 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/26 12:12:37 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*instr;

	a = NULL;
	b = NULL;
	instr = NULL;
	if (loadlist(argc, argv, &a) == 0)
	{
		write(2, "error\n", 6);
		return (1);
	}
	if (issorted(a))
	{
		ft_lstclear(&a, del);
		return (0);
	}
	sort_list(&a, &b, &instr);
	optimise_instr(instr);
	printlist_instr(instr);
	ft_lstclear(&a, del);
	ft_lstclear(&instr, del);
	return (0);
}
