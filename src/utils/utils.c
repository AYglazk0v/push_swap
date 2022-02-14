/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:25:37 by gtaggana          #+#    #+#             */
/*   Updated: 2022/02/13 12:26:43 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
/*
	The function returns the length of the string.
*/
int	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (*(s + n))
		n++;
	return (n);
}

/*
	The function compares two strings
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*
	The function clears the collection of words
*/
void	ft_free_list(char ***list)
{
	int	i;

	i = -1;
	while (list[0][++i])
	{
		free(list[0][i]);
		list[0][i] = NULL;
	}
	free(*list);
	*list = NULL;
}

/*
	The function converts a string into a number.
*/
t_lint	ft_atoi(const char *str)
{	
	t_lint	num;
	int		sign;

	sign = 1;
	num = 0;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
		if ((num >= __LONG_MAX__) && sign > 0)
			return (-1);
		if ((num > __LONG_MAX__) && sign < 0)
			return (0);
	}
	return (sign * num);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
