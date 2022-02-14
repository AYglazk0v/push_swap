/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:12:12 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:35:08 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc >= 2)
	{
		ft_create_env(&env);
		ft_get_stack_a(argc, argv, &env);
		ft_sort(&env);
		ft_clean_stacks(&env);
	}
	return (0);
}	
