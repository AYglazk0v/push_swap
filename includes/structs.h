/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:47:37 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:47:38 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "push_swap.h"

typedef long int			t_lint;
typedef struct s_list		t_list;
typedef struct s_env		t_env;
typedef struct s_param		t_param;

struct s_list
{
	t_lint		val;
	t_list		*next;
	t_list		*prev;
};

struct s_param
{
	t_lint	min;
	t_lint	pos_a;
	t_lint	pos_b;
};

struct s_env
{
	t_list		*a_head;
	t_list		*b_head;
	t_param		*prm;
	t_lint		a_size;
	t_lint		b_size;
	t_lint		cnt_op;
	int			option;
};

#endif
