/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:12:33 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:20:59 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

/*
	the function checks whether the stack is sorted.
*/
int	ft_is_sorted(t_list *head)
{
	t_list	*curr_elem;
	t_list	*last;

	curr_elem = head;
	last = head->prev;
	while (curr_elem != last)
	{
		if (curr_elem->val > curr_elem->next->val)
			return (0);
		curr_elem = curr_elem->next;
	}
	return (1);
}

static void	ft_eswap(t_lint *a, t_lint *b)
{
	t_lint	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
	The function returns a sorted stack array
	a_head -> head = 0;
	b_head -> head = 1; 
	!!! i = -1 !!!
*/
t_lint	*ft_find_srt_arr(t_env *env, t_lint i)
{
	t_lint	*arr;
	t_lint	y;

	arr = malloc(sizeof(t_lint) * env->a_size);
	if (!arr)
		return (NULL);
	while (++i < env->a_size)
	{
		arr[i] = env->a_head->val;
		env->a_head = env->a_head->next;
	}
	i = -1;
	while (++i < env->a_size - 1)
	{
		y = -1;
		while (++y < env->a_size - i - 1)
			if (arr[y] > arr[y + 1])
				ft_eswap(&arr[y], &arr[y + 1]);
	}
	return (arr);
}

/*
	Function for searching for MAX/MID/MIN values in the stack
	Return MID
*/
t_lint	ft_find_spec_val(t_lint *arr, t_lint size, t_lint *max, t_lint *min)
{
	*max = arr[size - 1];
	*min = arr[0];
	return (arr[size / 2]);
}
