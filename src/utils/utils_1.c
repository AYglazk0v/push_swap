/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:44:16 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 09:45:37 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

t_lint	ft_max(t_lint a, t_lint b)
{
	if (a > b)
		return (a);
	return (b);
}

t_lint	ft_min(t_lint a, t_lint b)
{
	if (a < b)
		return (a);
	return (b);
}

t_lint	ft_abs(t_lint a)
{
	if (a < 0)
		return (-a);
	return (a);
}
