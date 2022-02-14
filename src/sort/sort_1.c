/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:12:27 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:18:09 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

/*
	Function for sorting triples of stack A
*/
void	ft_sort_a_tree(t_env *env)
{
	t_lint		max;
	t_lint		min;
	t_lint		mid;
	t_lint		*sorted_arr;

	sorted_arr = ft_find_srt_arr(env, -1);
	mid = ft_find_spec_val(sorted_arr, env->a_size, &max, &min);
	if (env->a_head->val == max)
		ft_rotate(env, 0, 1);
	if (env->a_head->val == mid)
	{
		if (env->a_head->next->val == max)
			ft_revrotate(env, 0, 1);
		else
			ft_swap(env, 0, 1);
		free(sorted_arr);
		return ;
	}
	if (env->a_head->next->val == max)
	{
		ft_revrotate(env, 0, 1);
		ft_swap(env, 0, 1);
	}
	free(sorted_arr);
}

/*
	Function for sorting up to 5 elements
*/
void	ft_mini_sort(t_env *env)
{
	if (ft_is_sorted(env->a_head) || env->a_size == 1)
		return ;
	else if (env->a_size == 2 && !ft_is_sorted(env->a_head))
		ft_swap(env, 0, 1);
	else if (env->a_size == 3)
		ft_sort_a_tree(env);
	else if (env->a_size == 5 || env->a_size == 4)
	{
		ft_push(env, 0, 1);
		if (env->a_size == 4)
			ft_push(env, 0, 1);
		ft_sort_a_tree(env);
		ft_full_srt(env);
	}
}

/*
	the function pushes all elements in b, except max min mid.
*/
void	ft_push2b(t_env	*env)
{
	t_lint	max;
	t_lint	min;
	t_lint	mid;
	t_lint	*arr;

	arr = ft_find_srt_arr(env, -1);
	mid = ft_find_spec_val(arr, env->a_size, &max, &min);
	while (env->a_size > 3)
	{
		if (env->a_head->val != min && env->a_head->val != max
			&& env->a_head->val != mid)
			ft_push(env, 0, 1);
		else
			ft_rotate(env, 0, 1);
	}
	free(arr);
	arr = NULL;
	ft_sort_a_tree(env);
}

void	ft_init_param(t_lint *m, t_lint *a, t_lint *b, int *o)
{
	*a = 0;
	*b = 0;
	*o = 0;
	*m = 2147483647;
}
