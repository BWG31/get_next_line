/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:38:45 by bgolding          #+#    #+#             */
/*   Updated: 2023/11/20 15:22:59 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_reader
{
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_to_cat;
	int			bytes_read;
}				t_reader;

char			*get_next_line(int fd);
char			*read_new_line(int fd, char *line, char *leftovers);
char			*ft_strchr(const char *s, int c);
char			*leftover_line(char *leftovers);
char			*free_cat(char *left, char *right, int len);
void			*clean_up(void *p, char *leftovers);
char			*ft_strcpy(char *dest, char *src);

#endif
