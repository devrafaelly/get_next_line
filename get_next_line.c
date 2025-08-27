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
    char    char_read[BUFFER_SIZE];
    int bytes_read;
    
    fd = open("bittersuite.txt", O_RDONLY);
    if (fd < 0)
        return (-1);
    while (bytes_read != 0)
    {
        bytes_read = read(fd, BUFFER_SIZE, char_read);
    }
    close(fd);
}
// como mallocar esse rest? deixar toda a memoria mallocada com \0
char    *armazenamento_retorno(char *char_read)
{
    static char    *rest;
    char    *line;
    int i;
    int j;
    
    i = 0;
    while (*rest)
    {
        if (*rest == '\n')
        {
            line = malloc(i);
            if(!line)
                return (NULL);
            i = 0;
            while (rest[i] != '\n')
            {
                line[j] = rest[i];
            }
            line[j] = '\n';
            return (line);
        }
        rest++;
        i++;
    }
    rest = data_clean(rest, j);
    j = 0;
    while (char_read[j])
    {
        rest[i] = char_read[j];
        i++;
        j++;
    }
}

char    *data_clean(char *rest, int i)
{
    int j;
    int end;

    end = i;
    j = 0;
    while (*rest)
    {
        rest[j] = rest [i];
        j++;
        i++;
    }
    return (rest);
}