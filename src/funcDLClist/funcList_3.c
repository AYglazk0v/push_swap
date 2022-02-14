/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcList_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:12:51 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:31:11 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/funcList.h"

/*
	The function adds the number = value to stack A.
*/
void	ft_add_elem(t_env *ring, int value)
{
	t_list	*p;
	t_list	*tmp;

	tmp = (t_list *) malloc(sizeof(t_list));
	tmp->val = value;
	if (ring->a_head == NULL)
	{
		ring->a_head = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		p = ring->a_head->prev;
		ring->a_head->prev = tmp;
		tmp->prev = p;
		tmp->next = ring->a_head;
		p->next = tmp;
	}
	ring->a_size++;
}

/*
	Function for adding the top element from A to B.
*/
static void	ft_a2b(t_env *env)
{
	t_list	*tmp;
	t_list	*p;	

	tmp = env->a_head;
	p = env->a_head->next;
	env->a_head->prev->next = p;
	p->prev = env->a_head->prev;
	env->a_head = p;
	if (!env->b_head)
	{
		env->b_head = tmp;
		env->b_head->next = tmp;
		env->b_head->prev = tmp;
	}
	else
	{
		p = env->b_head->prev;
		env->b_head->prev = tmp;
		tmp->prev = p;
		tmp->next = env->b_head;
		p->next = tmp;
		ft_revrotate(env, 1, 0);
	}
	env->b_size++;
	env->a_size--;
}

/*
	Function for adding the top element from B to A.
*/
static void	ft_b2a(t_env *env)
{
	t_list	*tmp;
	t_list	*p;	

	tmp = env->b_head;
	p = env->b_head->next;
	env->b_head->prev->next = p;
	p->prev = env->b_head->prev;
	env->b_head = p;
	if (!env->a_head)
	{
		env->a_head = tmp;
		env->a_head->next = tmp;
		env->a_head->prev = tmp;
	}
	else
	{
		p = env->a_head->prev;
		env->a_head->prev = tmp;
		tmp->prev = p;
		tmp->next = env->a_head;
		p->next = tmp;
		ft_revrotate(env, 0, 0);
	}
	env->a_size++;
	env->b_size--;
}

/*
	The function performs a push depending on the direction parameter:
	pb -- direction = 0;
	pa -- direction = 1;
*/
void	ft_push(t_env *env, int direction, int say)
{
	if (direction == 0 && env->a_head)
	{
		ft_a2b(env);
		if (say)
			write(1, "pb\n", 3);
	}
	else if (direction == 1 && env->b_head)
	{
		ft_b2a(env);
		if (say)
			write(1, "pa\n", 3);
	}
	if (env->a_size == 0)
		env->a_head = NULL;
	if (env->b_size == 0)
		env->b_head = NULL;
}

void	ft_create_prm(t_env *env)
{
	env->prm = malloc(sizeof(t_param));
	env->prm->min = 2147483647;
	env->prm->pos_a = 0;
	env->prm->pos_b = 0;
}
