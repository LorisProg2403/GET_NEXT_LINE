/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:59:27 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/01 15:59:30 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char		*get_next_line(int fd);
char 		*read_save(int fd, char *save);
size_t		ft_strlen(char *s);
char 		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *str, int c);
char 		*newline(char *save);
char 		*clean_save(char *save);
void		free_stash(char **stash);

#endif