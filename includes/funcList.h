/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcList.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:11:35 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:11:38 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCLIST_H
# define FUNCLIST_H

# include "push_swap.h"

//funcList_1.c

void		ft_create_env(t_env *env);
void		ft_rotate(t_env *ring, int head, int say);
void		ft_revrotate(t_env *ring, int head, int say);

//funcList_2.c

void		ft_swap(t_env *env, int head, int say);
void		ft_clean_stacks(t_env *ring);

//funcList_3.c

void		ft_add_elem(t_env *ring, int value);
void		ft_push(t_env *env, int direction, int say);
void		ft_create_prm(t_env *env);

#endif
