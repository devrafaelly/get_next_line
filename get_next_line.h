/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:44:08 by codespace         #+#    #+#             */
/*   Updated: 2025/08/27 17:34:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd);
char    *rest_is_true(char **rest, char *char_read, int bytes);
char    *get_line(char *char_read, char **rest, int bytes);
char    *update_rest(char *rest, int len, int i, int bytes);
char	*ft_strdup(const char *s, size_t len);

void	*ft_memcpy(void *dest, const void *src, size_t n);

size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif