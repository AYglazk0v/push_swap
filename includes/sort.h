/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:11:55 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:14:05 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

//sort.c

void	ft_sort(t_env *env);
void	ft_full_srt(t_env *env);

//sort_1.c

void	ft_sort_a_tree(t_env *env);
void	ft_mini_sort(t_env *env);
void	ft_push2b(t_env *env);

//sort_utils_1.c

int		ft_is_sorted(t_list *head);
t_lint	*ft_find_srt_arr(t_env *env, t_lint i);
t_lint	ft_find_spec_val(t_lint *arr, t_lint size, t_lint *max, t_lint *min);
void	ft_init_param(t_lint *m, t_lint *a, t_lint *b, int *o);

//options.c
void	opt_1(t_env *env);
void	opt_2(t_env *env);
void	opt_3(t_env *env);
void	opt_4(t_env *env);
void	finale_rotate(t_env *env, int i);

#endif
