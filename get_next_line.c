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
    char char_read[BUFFER_SIZE];
    int bytes_read;
    
    fd = open("bittersuite.txt", O_RDONLY);
    if (fd < 0)
        return (-1);
    bytes_read = read(BUFFER_SIZE, char_read);
    close(fd);
}

char    *armazenar_caracteres(char *char_read)
{
    int i;
    
    i = 0;
    while (char_read[i] || char_read != '\n')
    {
        
    }
}