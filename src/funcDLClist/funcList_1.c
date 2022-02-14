/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcList_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:12:40 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:29:09 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/funcList.h"

/*
	Function for initializing the environment.
*/
void	ft_create_env(t_env *env)
{
	env->a_head = NULL;
	env->b_head = NULL;
	env->a_size = 0;
	env->b_size = 0;
	env->cnt_op = 0;
	env->option = 0;
	env->prm = NULL;
	ft_create_prm(env);
}

/*
	The function takes a doubly connected ring list and rotates it.
	The next element becomes the head element.
*/
static t_list	*ft_next(t_env *ring, int head)
{
	t_list	*retval;

	retval = NULL;
	if (head == 0)
	{
		if (ring->a_head)
		{
			ring->a_head = ring->a_head->next;
			retval = ring->a_head;
		}
	}
	else
	{
		if (ring->b_head)
		{
			ring->b_head = ring->b_head->next;
			retval = ring->b_head;
		}
	}
	return (retval);
}

/*
	The function takes a doubly connected ring list and rotates it.
	The previous element becomes the head element.
*/
static t_list	*ft_prev(t_env *ring, int head)
{
	t_list	*retval;

	retval = NULL;
	if (head == 0)
	{
		if (ring->a_head)
		{
			ring->a_head = ring->a_head->prev;
			retval = ring->a_head;
		}
	}
	else
	{
		if (ring->b_head)
		{
			ring->b_head = ring->b_head->prev;
			retval = ring->b_head;
		}
	}
	return (retval);
}

/*
	The function rotates stacks A and B depending on the head parameter:
	rra -> head = 0 
	rrb -> head = 1
	rrr -> head = 2
*/
void	ft_revrotate(t_env *ring, int head, int say)
{
	if (head == 0)
	{
		ring->a_head = ft_prev(ring, 0);
		if (say)
			write(1, "rra\n", 4);
	}
	else if (head == 1)
	{
		ring->b_head = ft_prev(ring, 1);
		if (say)
			write(1, "rrb\n", 4);
	}
	else
	{
		ring->a_head = ft_prev(ring, 0);
		ring->b_head = ft_prev(ring, 1);
		if (say)
			write(1, "rrr\n", 4);
	}
}

/*
	The function reverse rotates stacks A and B
	depending on the head parameter:
	ra -> head = 0 
	rb -> head = 1
	rr -> head = 2
*/
void	ft_rotate(t_env *ring, int head, int say)
{
	if (head == 0)
	{
		ring->a_head = ft_next(ring, 0);
		if (say)
			write(1, "ra\n", 3);
	}
	else if (head == 1)
	{
		ring->b_head = ft_next(ring, 1);
		if (say)
			write(1, "rb\n", 3);
	}
	else
	{
		ring->a_head = ft_next(ring, 0);
		ring->b_head = ft_next(ring, 1);
		if (say)
			write(1, "rr\n", 3);
	}
}
