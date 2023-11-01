/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:36:57 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/01 04:27:22 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdlib.h"
# include "unistd.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char		*get_next_line(int fd);
void		read_and_stash(int fd, t_list **stash);
void		add_to_stash(t_list **stash, char *buff, int readed);
t_list		*lst_get_last(t_list *lst);
int			found_newline(t_list *stash);
void		extract_line(t_list *stash, char **line);
void		generate_line(char **line, t_list *stash);
void		clean_stash(t_list **stash);
int			ft_strlen(char *s);
void		free_stash(t_list *stash);

#endif
