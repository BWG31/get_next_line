/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:38:32 by bgolding          #+#    #+#             */
/*   Updated: 2023/11/20 18:02:42 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	leftovers[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (clean_up(NULL, leftovers));
	line = leftover_line(leftovers);
	if (!line)
		return (NULL);
	if (!ft_strchr(line, '\n'))
		line = read_new_line(fd, line, leftovers);
	if (!line)
		return (NULL);
	if (*line == '\0')
		return (clean_up(line, leftovers));
	return (line);
}

char	*read_new_line(int fd, char *line, char *leftovers)
{
	t_reader	r;
	char		*p;

	p = NULL;
	r.bytes_read = BUFFER_SIZE;
	while (!p && r.bytes_read == BUFFER_SIZE)
	{
		r.bytes_read = read(fd, r.buffer, BUFFER_SIZE);
		if (r.bytes_read == -1)
			return (clean_up(line, leftovers));
		r.buffer[r.bytes_read] = '\0';
		p = ft_strchr(r.buffer, '\n');
		if (p)
		{
			ft_strcpy(leftovers, p + 1);
			r.bytes_to_cat = p - r.buffer + 1;
		}
		else
			r.bytes_to_cat = r.bytes_read;
		line = free_cat(line, r.buffer, r.bytes_to_cat);
		if (!line)
			return (NULL);
	}
	return (line);
}
