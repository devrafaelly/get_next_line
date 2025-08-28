/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:44:10 by codespace         #+#    #+#             */
/*   Updated: 2025/08/27 18:13:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char    *rest;
    char    char_read[BUFFER_SIZE];
    char    *line;
    int bytes_read;
    
    bytes_read = 1;
    while (bytes_read != 0)
    {
        bytes_read = read(fd, char_read, BUFFER_SIZE);
        if (bytes_read < 0)
            return (NULL);
        if (rest)
            line = rest_is_true(&rest, char_read, bytes_read);
        else
            line = get_line(char_read, &rest, bytes_read);
        if (line)
            return (line);
    }
    if (bytes_read == 0 && rest)
    {
        line = ft_strdup(rest, ft_strlen(rest));
        free (rest);
        return (line);
    }
    return (NULL);
}

char    *rest_is_true(char **rest, char *char_read, int bytes)
{
    char    *line;
    int i;

    i = 0;
    while ((*rest)[i])
    {
        if ((*rest)[i] == '\n')
        {
            line = ft_strdup(*rest, i + 1);
            *rest = refresh_rest(*rest, i + 1, 0);
            return (line);
        }
        i++;
    }
    *rest = ft_strdup(char_read, bytes);
    return (NULL);
}

char    *get_line(char *char_read, char **rest, int bytes)
{
    char    *line;
    int i;
    
    i = 0;
    while (i < bytes)
    {
        if (char_read[i] == '\n')
        {
            line = ft_strdup(char_read, i + 1);
            *rest = malloc(bytes - i - 1);
            ft_memcpy(*rest, &char_read[i + 1], (bytes - i - 1));
            return (line);
        }
        i++;
    }
    *rest = malloc(bytes + 1);
    if (!(*rest))
        return (NULL);
    ft_memcpy(*rest, char_read, bytes);
    return (NULL);
}

char    **refresh_rest(char **rest, int i, int bytes)
{
    char    *temp;
    int j;

    j = ft_strlen(&(*rest)[i]);
    temp = malloc(j + 1);
    if (!temp)
        return (NULL);
    ft_memcpy(temp, *rest + i, (j + 1));
    free(*rest);
    *rest = malloc (bytes + j + 1);
    if (!(*rest))
        return (NULL);
    ft_memcpy(*rest, temp, (j + 1));
    free(temp);
    return (**rest);
}