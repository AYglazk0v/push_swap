/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcList_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:12:47 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:32:14 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/funcList.h"

/*
	The function changes the val and score of the top two elements.
*/
static void	ft_swap2elem(t_list *stack)
{
	t_lint	val;

	val = stack->val;
	stack->val = stack->next->val;
	stack->next->val = val;
}

/*
	The function performs a swap 
	for the top two elements depending on the head parameter:
	sa -> head = 0
	sb -> head = 1
	ss -> head = 2
*/
void	ft_swap(t_env *env, int head, int say)
{
	if (head == 0 && env->a_head)
	{
		ft_swap2elem(env->a_head);
		if (say)
			write(1, "sa\n", 3);
	}
	else if (head == 1 && env->b_head)
	{
		ft_swap2elem(env->b_head);
		if (say)
			write(1, "sb\n", 3);
	}
	else if (head == 3 && env->b_head && env->a_head)
	{
		ft_swap2elem(env->a_head);
		ft_swap2elem(env->b_head);
		if (say)
			write(1, "ss\n", 3);
	}
}

/*
	Function for removing items from stack A
*/
t_lint	ft_remove_elem_a(t_env *ring)
{
	t_list	*after;
	t_lint	retval;

	after = NULL;
	if (ring->a_head == NULL)
		return (-2147483649);
	if (ring->a_head->next == ring->a_head)
	{
		retval = ring->a_head->val;
		free(ring->a_head);
		ring->a_head = NULL;
	}
	else
	{
		after = ring->a_head->next;
		ring->a_head->prev->next = after;
		after->prev = ring->a_head->prev;
		retval = ring->a_head->val;
		free(ring->a_head);
		ring->a_head = after;
	}
	ring->a_size--;
	return (retval);
}

/*
	Function for removing items from stack B
*/
t_lint	ft_remove_elem_b(t_env *ring)
{
	t_list	*after;
	t_lint	retval;

	after = NULL;
	if (ring->b_head == NULL)
		return (-2147483649);
	if (ring->b_head->next == ring->b_head)
	{
		retval = ring->b_head->val;
		free(ring->b_head);
		ring->b_head = NULL;
	}
	else
	{
		after = ring->b_head->next;
		ring->b_head->prev->next = after;
		after->prev = ring->b_head->prev;
		retval = ring->b_head->val;
		free(ring->b_head);
		ring->b_head = after;
	}
	ring->a_size--;
	return (retval);
}

/*
	Function for clearing stacks.
*/
void	ft_clean_stacks(t_env *ring)
{
	t_lint	response;

	response = 1;
	while (response != -2147483649)
		response = ft_remove_elem_a(ring);
	response = 1;
	while (response != -2147483649)
		response = ft_remove_elem_b(ring);
	free(ring->prm);
	ring->prm = NULL;
}
