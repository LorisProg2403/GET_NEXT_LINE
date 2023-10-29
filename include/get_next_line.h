/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 03:47:35 by lgaume            #+#    #+#             */
/*   Updated: 2023/10/29 03:47:37 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdlib.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct	s_list
{
	char 			*content;
	struct s_list	*next;
}	t_list;

char		*get_next_line(int fd);

#endif
