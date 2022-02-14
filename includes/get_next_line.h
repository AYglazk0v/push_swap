/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:48:54 by gtaggana          #+#    #+#             */
/*   Updated: 2021/10/27 20:55:52 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1	
# endif

# include "push_swap.h"
# include <string.h>

size_t		ft_gnl_strlen(char *s);
char		*ft_strchr(char *string, int symbol);
char		*get_next_line(int fd);

#endif
