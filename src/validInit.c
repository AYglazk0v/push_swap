/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validInit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:12:16 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:34:44 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	The function glues lines separated by a space. 
	Input parameters are string1, string 2, -1, 0. Glory to norminette!
*/
static char	*ft_strjion_space(char *s1, char *s2, size_t i, size_t j)
{
	char	*join;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!(s1 && s2))
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 3));
	if (!join)
		return (NULL);
	while (s1[++i])
		join[i] = s1[i];
	join[i++] = ' ';
	while (s2[j])
		join[i++] = s2[j++];
	join[i++] = ' ';
	join[i] = '\0';
	free(s1);
	return (join);
}

/*
	checking that our words consist of numbers and spaces
*/
static void	ft_validchr(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] && argv[i][j] == ' ')
				j++;
			if (argv[i][j] && (argv[i][j] == '+' || argv[i][j] == '-'))
				j++;
			while (argv[i][j] && ft_isdigit(argv[i][j]))
				j++;
			if (argv[i][j] && argv[i][j] != ' ')
			{
				write(2, "Error\n", 6);
				exit(1);
			}
		}
		i++;
	}
}

/*
	Checking for repetitions
*/
static void	ft_validdup(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = i + 1;
		while (list[j] && (ft_strcmp(list[i], list[j]) != 0))
			j++;
		if (list[j] && (ft_strcmp(list[i], list[j]) == 0))
		{
			write(2, "Error\n", 6);
			ft_free_list(&list);
			exit(2);
		}
		i++;
	}
}

/*
	The function converts strings with numbers and 
	fills the stack A if they are in the int range.
*/
static void	ft_list2stack(char **list, t_env *env)
{
	int		i;
	t_lint	j;

	i = -1;
	while (list[++i])
	{
		j = ft_atoi(list[i]);
		if (j < -2147483648 || j > 2147483647)
		{
			ft_clean_stacks(env);
			write(2, "Error\n", 6);
			exit(3);
		}
		else
			ft_add_elem(env, j);
	}
}

/*
	The function returns a filled stack A, if no validation errors occurred.
*/
void	ft_get_stack_a(int argc, char **argv, t_env *env)
{
	char	*tmp;
	char	**list;
	int		i;

	i = 0;
	tmp = NULL;
	ft_validchr(argc, argv);
	while (++i < argc)
		tmp = ft_strjion_space(tmp, argv[i], -1, 0);
	list = ft_split(tmp, ' ');
	free(tmp);
	tmp = NULL;
	ft_validdup(list);
	ft_list2stack(list, env);
	ft_free_list(&list);
}
