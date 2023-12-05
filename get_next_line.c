/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:36:01 by ialdidi           #+#    #+#             */
/*   Updated: 2023/12/05 18:23:35 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	update_line(char **str)
{
	char	*tmp;

	tmp = *str;
	while (*tmp && *tmp != '\n')
		tmp++;
	if (*tmp != '\n')
	{
		free(*str);
		*str = NULL;
		tmp = NULL;
		return ;
	}
	if (*(++tmp))
	{
		tmp = ft_strdup(tmp);
		if (!tmp)
			return (free(*str), *str = NULL, (void) NULL);
	}
	else
	{
		tmp = NULL;
	}
	free(*str);
	*str = tmp;
	tmp = NULL;
}

char	*create_line(char *str)
{
	char	*extracted_line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i = i + 1 * (str[i] == '\n');
	extracted_line = (char *)malloc(i + 1);
	if (!extracted_line)
		return (free(str), str = NULL, NULL);
	i = -1;
	while (str[++i])
	{
		extracted_line[i] = str[i];	
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
	}
	extracted_line[i] = '\0';
	return (extracted_line);
}

void	insert_line(char **str, char *buffer, char **nl)
{
	char	*tmp;

	*nl = ft_strchr(buffer, '\n');
	tmp = ft_strdup(*str);
	if (!tmp)
		return (free(*str), (void)(*str = NULL));
	free(*str);
	*str = NULL;
	*str = ft_strjoin(tmp, buffer);
	free(tmp);
	tmp = NULL;
}

void	read_line(int fd, char **str)
{
	char	*buffer;
	char	*nl;
	int		rd;

	nl = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(*str), (void)(*str = NULL));
	while (!nl)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
		{
			free(buffer);
			buffer = NULL;
			return ;
		}
		buffer[rd] = '\0';
		insert_line(str, buffer, &nl);
	}
	free(buffer);
	buffer = NULL;
}
#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > 2147483647 || read(fd, NULL, 0) < 0)
		return (free(str), str = NULL);
	if (!str || !ft_strchr(str, '\n'))
		read_line(fd, &str);
	if (!str)
		return (NULL);
	line = create_line(str);
	if (!line)
		return (str = NULL);
	update_line(&str);
	return (line);
}
