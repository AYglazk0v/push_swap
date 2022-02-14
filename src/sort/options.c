/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:12:21 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:25:17 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

void	opt_1(t_env *env)
{
	t_lint	op_do;

	op_do = ft_min(env->prm->pos_a, env->prm->pos_b);
	while (op_do--)
		ft_rotate(env, 2, 1);
	op_do = ft_abs((env->prm->pos_a - env->prm->pos_b));
	if (env->prm->pos_a > env->prm->pos_b)
	{
		while (op_do--)
			ft_rotate(env, 0, 1);
	}
	else if (env->prm->pos_a < env->prm->pos_b)
	{
		while (op_do--)
			ft_rotate(env, 1, 1);
	}
	ft_push(env, 1, 1);
}

void	opt_2(t_env *env)
{
	t_lint	op_do;

	op_do = env->prm->pos_a;
	while (op_do--)
		ft_rotate(env, 0, 1);
	op_do = env->b_size - env->prm->pos_b;
	while (op_do--)
		ft_revrotate(env, 1, 1);
	ft_push(env, 1, 1);
}

void	opt_3(t_env *env)
{
	t_lint	op_do;

	op_do = env->prm->pos_b;
	while (op_do--)
		ft_rotate(env, 1, 1);
	op_do = env->a_size - env->prm->pos_a;
	while (op_do--)
		ft_revrotate(env, 0, 1);
	ft_push(env, 1, 1);
}

void	opt_4(t_env *env)
{
	t_lint	op_do;

	op_do = ft_min(env->a_size - env->prm->pos_a,
			env->b_size - env->prm->pos_b);
	while (op_do--)
		ft_revrotate(env, 2, 1);
	op_do = ft_abs(((env->a_size - env->prm->pos_a)
				- (env->b_size - env->prm->pos_b)));
	if (env->a_size - env->prm->pos_a > env->b_size - env->prm->pos_b)
	{
		while (op_do--)
			ft_revrotate(env, 0, 1);
	}
	else if (env->a_size - env->prm->pos_a < env->b_size - env->prm->pos_b)
	{
		while (op_do--)
		{
			ft_revrotate(env, 1, 1);
		}
	}
	ft_push(env, 1, 1);
}

void	finale_rotate(t_env *env, int i)
{
	int	min;
	int	min_pos;
	int	tmp_pos;

	min = 2147483647;
	min_pos = 0;
	tmp_pos = 0;
	while (++i < env->a_size)
	{
		if (env->a_head->val < min)
		{
			min = env->a_head->val;
			min_pos = tmp_pos;
		}
		env->a_head = env->a_head->next;
		tmp_pos++;
	}
	if (min_pos > env->a_size / 2)
		while (env->a_head->val != min)
			ft_revrotate(env, 0, 1);
	else
		while (env->a_head->val != min)
			ft_rotate(env, 0, 1);
}
