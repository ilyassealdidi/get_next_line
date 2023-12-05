/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:36:01 by ialdidi           #+#    #+#             */
/*   Updated: 2023/12/05 16:41:47 by ialdidi          ###   ########.fr       */
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
	tmp = ft_strdup(++tmp);
	if (!tmp)
		return ;
	free(*str);
	*str = tmp;
	tmp = NULL;
}

char	*create_line(char *str)
{
	char	*extracted_line;
	int		i;
	int		len;

	len = 0;
	while (str[len])
		len++;
	len = len + 1 * (str[len] == '\n');
	extracted_line = (char *)malloc(len + 1);
	if (!extracted_line)
		return (free(str), str = NULL, NULL);
	i = -1;
	while (++i <= len)
		extracted_line[i] = str[i];
	return (extracted_line);
}

void	insert_line(char **str, char *buffer, char **nl)
{
	char	*tmp;

	*nl = ft_strchr(buffer, '\n');
	tmp = ft_strdup(*str);
	if (!tmp)
	{
		*nl = NULL;
		return ;
	}
	free(*str);
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
		return ;
	while (!nl)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
		{
			free(*str);
			free(buffer);
			buffer = NULL;
			str = NULL;
			return ;
		}
		buffer[rd] = '\0';
		insert_line(str, buffer, &nl);
	}
	free(buffer);
	buffer = NULL;
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > 2147483647 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!str || !ft_strchr(str, '\n'))
		read_line(fd, &str);
	if (!str)
		return (NULL);
	line = create_line(str);
	if (!line)
		return (NULL);
	update_line(&str);
	return (line);
}
