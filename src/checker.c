/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:10:52 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:35:52 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

int	ft_valid_cmd(char *cmd, t_env *env)
{
	if (!ft_strcmp(cmd, "sa\n"))
		ft_swap(env, 0, 0);
	else if (!ft_strcmp(cmd, "sb\n"))
		ft_swap(env, 1, 0);
	else if (!ft_strcmp(cmd, "ss\n"))
		ft_swap(env, 2, 0);
	else if (!ft_strcmp(cmd, "ra\n"))
		ft_rotate(env, 0, 0);
	else if (!ft_strcmp(cmd, "rb\n"))
		ft_rotate(env, 1, 0);
	else if (!ft_strcmp(cmd, "rr\n"))
		ft_rotate(env, 2, 0);
	else if (!ft_strcmp(cmd, "rra\n"))
		ft_revrotate(env, 0, 0);
	else if (!ft_strcmp(cmd, "rrb\n"))
		ft_revrotate(env, 1, 0);
	else if (!ft_strcmp(cmd, "rrr\n"))
		ft_revrotate(env, 2, 0);
	else if (!ft_strcmp(cmd, "pa\n"))
		ft_push(env, 1, 0);
	else if (!ft_strcmp(cmd, "pb\n"))
		ft_push(env, 0, 0);
	else
		return (0);
	return (1);
}

static void	ft_check_str(t_env *env)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		else if (!ft_valid_cmd(cmd, env))
		{
			write (1, "Error\n", 6);
			exit(1);
		}
		free(cmd);
	}
	if (ft_is_sorted(env->a_head))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc > 1)
	{
		ft_create_env(&env);
		ft_get_stack_a(argc, argv, &env);
		ft_check_str(&env);
		ft_clean_stacks(&env);
	}
	return (0);
}
