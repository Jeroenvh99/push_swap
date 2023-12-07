/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:14:20 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/26 10:19:47 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include"./libft/libft.h"

void	printlist_instr(t_list *head);
int		lstsearch(t_list *lst, int *num);
void	del(void *node);
int		issorted(t_list *lst);
int		loadlist(int argc, char **argv, t_list **a);
int		getextreme(t_list *lst, int high_or_low);

t_list	*swap(t_list *lst);
void	push(t_list **lst1, t_list **lst2);
t_list	*rotate(t_list *lst);
t_list	*rrotate(t_list *lst);

void	sort_three(t_list **a, t_list **instr);
void	sort_list(t_list **a, t_list **b, t_list **instr);
void	smart_rotate_stack_a(int rotations, int size, t_list **instr);
void	smart_rotate_stack_b(int rotations, int size, t_list **instr);
int		getcurrent(t_list *lst, int i);
int		get_cheapest_ab(t_list *a, t_list *b);
int		get_cheapest_ba(t_list *a, t_list *b);
void	optimise_instr(t_list *lst);
void	move_to_top(t_list **a, int to_push, t_list **instr,
			void (*smart_rotate)(int, int, t_list**));
void	finalalignment(t_list **a, t_list **instr);
#endif
