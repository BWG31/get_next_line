/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:38:48 by bgolding          #+#    #+#             */
/*   Updated: 2023/11/20 14:22:43 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	Searches string 's' for char 'c'. Includes the '\0' char.
	Returns a pointer to the first occurrence found, or NULL if not found.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
	Copies leftovers, up to and including the first '\n' or '\0'
	(whichever comes first), from leftovers to a new string ('line')
	allocated with malloc(3). Then copies any remaining characters
	(if '\n' found), to the start of leftovers.
	Always null terminates the new leftovers. Returns 'line'.
*/
char	*leftover_line(char *leftovers)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (leftovers[i] && !(leftovers[i] == '\n'))
		i++;
	if (leftovers[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = -1;
	while (++j < i)
		line[j] = leftovers[j];
	line[j] = '\0';
	j = 0;
	while (leftovers[i])
		leftovers[j++] = leftovers[i++];
	leftovers[j] = '\0';
	return (line);
}

/*
	Concatenates 'right' to 'left' in a new string allocated with
	malloc(3). Will only concatenate up to 'len' characters of 'right'.
	Will then free() the original 'left'.
	Null terminates and returns the new string.
*/
char	*free_cat(char *left, char *right, int len)
{
	char	*s;
	int		i;
	int		j;

	if (len <= 0)
		return (left);
	i = 0;
	while (left[i])
		i++;
	s = malloc(i + len + 1);
	if (!s)
		return (clean_up(left, NULL));
	j = -1;
	while (++j < i)
		s[j] = left[j];
	i = 0;
	while (i < len)
		s[j++] = right[i++];
	s[j] = '\0';
	free(left);
	return (s);
}

/*
	Will free any memory allocated to pointer 'p' and "reset" 'leftovers'
	by setting the first character of the string to NULL.
*/
void	*clean_up(void *p, char *leftovers)
{
	if (p)
		free(p);
	if (leftovers)
		*leftovers = '\0';
	return (NULL);
}

/*
	Copies string 'src' to 'dest', always null terminanting 'dest'.
*/
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
