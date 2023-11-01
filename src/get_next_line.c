/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:37:13 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/01 04:38:46 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	read_and_stash(fd, &stash);
	if (!stash)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (!line[0])
	{
		free(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

/* Utilise read() pour ajouter des charachteres a la stash */

void	read_and_stash(int fd, t_list **stash)
{
	int		readed;
	char	*buff;

	readed = 1;
	while (!found_newline(*stash) && readed != 0)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		readed = read(fd, buff, BUFFER_SIZE);
		if ((!(*stash) && !readed) || readed == -1)
		{
			free(buff);
			return ;
		}
		buff[readed] = '\0';
		add_to_stash(stash, buff, readed);
		free(buff);
	}
}

/* Ajoute le contenu du buffer a la stash */

void	add_to_stash(t_list **stash, char *buff, int readed)
{
	int		i;
	t_list	*new;
	t_list	*last;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (readed + 1));
	if (!new->content)
		return ;
	i = 0;
	while (buff[i] && i < readed)
	{
		new->content[i] = buff[i];
		i++;
	}
	new->content[i] = '\0';
	if (!(*stash))
		*stash = new;
	else
	{
		last = lst_get_last(*stash);
		last->next = new;
	}
}

/* Extrait tous les characteres de la stash and les stockent dans la
 * ligne en s'arretant a la premiere occurence de \n. */

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (!stash)
		return ;
	generate_line(line, stash);
	if (!*line)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = '\n';
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

/* Nettoie la stash pour que seuls les characteres qui n'ont pas
 * ete retournes reste dans la STATIC stash */

void	clean_stash(t_list **stash)
{
	t_list	*clean;
	t_list	*last;
	int		i;
	int		j;

	clean = malloc(sizeof(t_list));
	if (!clean)
		return ;
	clean->next = NULL;
	last = lst_get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean->content = malloc(sizeof(char) * (ft_strlen(last->content) - 1 + 1));
	if (!clean->content)
		return ;
	j = 0;
	while (last->content[i])
		clean->content[j++] = last->content[i++];
	clean->content[j] = '\0';
	free_stash(*stash);
	*stash = clean;
}
