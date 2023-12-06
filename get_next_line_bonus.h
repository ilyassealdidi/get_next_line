/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:30:39 by ialdidi           #+#    #+#             */
/*   Updated: 2023/12/06 12:55:29 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
void	insert_line(char **str, char *buffer);
char	*create_line(char *str);
void	read_line(int fd, char **str);
void	update_line(char **str);
char	*get_next_line(int fd);

#endif