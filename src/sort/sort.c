/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:12:25 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:22:39 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

/*
	A function that determines which push method to choose.
*/
static void	ft_choice_opt(t_env *env)
{
	int	cnt_op;

	env->cnt_op = ft_max(env->prm->pos_a, env->prm->pos_b);
	env->option = 1;
	cnt_op = env->prm->pos_a + (env->b_size - env->prm->pos_b);
	if (cnt_op < env->cnt_op)
	{
		env->cnt_op = cnt_op;
		env->option = 2;
	}
	cnt_op = env->prm->pos_b + (env->a_size - env->prm->pos_a);
	if (cnt_op < env->cnt_op)
	{
		env->cnt_op = cnt_op;
		env->option = 3;
	}
	cnt_op = ft_max(env->a_size - env->prm->pos_a,
			env->b_size - env->prm->pos_b);
	if (cnt_op < env->cnt_op)
	{
		env->cnt_op = cnt_op;
		env->option = 4;
	}
	env->cnt_op++;
}

/*
	Function for getting a position in stack A.
*/
static void	ft_find_pos_a(t_env *env, t_lint val, int j)
{
	t_lint	i;

	i = 0;
	while (++j < env->a_size)
	{
		if (val > env->a_head->val && val < env->a_head->next->val)
			env->prm->pos_a = i + 1;
		else if (val < env->a_head->val && val < env->a_head->next->val
			&& env->a_head->val > env->a_head->next->val)
			env->prm->pos_a = i + 1;
		else if (val > env->a_head->val
			&& env->a_head->val > env->a_head->next->val)
			env->prm->pos_a = i + 1;
		i++;
		env->a_head = env->a_head->next;
	}
	if (val > env->a_head->val && val < env->a_head->val)
		env->prm->pos_a = env->a_size;
}

/*
	Function for getting a position in stack B.
*/
static void	ft_find_pos_b(t_env *env, t_lint i, int j)
{
	t_lint	min;
	t_lint	a_pos;
	t_lint	b_pos;
	int		op;

	ft_init_param(&min, &a_pos, &b_pos, &op);
	while (++j < env->b_size)
	{
		env->prm->pos_b = ++i;
		ft_find_pos_a(env, env->b_head->val, -1);
		ft_choice_opt(env);
		if (env->cnt_op < min)
		{
			min = env->cnt_op;
			a_pos = env->prm->pos_a;
			b_pos = i;
			op = env->option;
		}
		env->b_head = env->b_head->next;
	}
	env->cnt_op = min;
	env->option = op;
	env->prm->pos_a = a_pos;
	env->prm->pos_b = b_pos;
}

/*
	The main function for sorting an array.
*/
void	ft_full_srt(t_env	*env)
{
	while (env->b_head)
	{
		ft_find_pos_b(env, -1, -1);
		if (env->option == 1)
			opt_1(env);
		else if (env->option == 2)
			opt_2(env);
		else if (env->option == 3)
			opt_3(env);
		else if (env->option == 4)
			opt_4(env);
	}
	finale_rotate(env, -1);
}

void	ft_sort(t_env *env)
{
	if (ft_is_sorted(env->a_head))
		return ;
	if (env->a_size < SMALLDIMENSION)
		ft_mini_sort(env);
	else
	{
		ft_push2b(env);
		ft_full_srt(env);
	}
}
