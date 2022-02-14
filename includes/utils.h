/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:11:08 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:11:43 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"

//utils.c

int		ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
void	ft_free_list(char ***list);
t_lint	ft_atoi(const char *str);
int		ft_isdigit(int c);

//utils_1.c

t_lint	ft_max(t_lint a, t_lint b);
t_lint	ft_min(t_lint a, t_lint b);
t_lint	ft_abs(t_lint a);

//ft_split.c

char	**ft_split(char const *s, char c);

#endif
