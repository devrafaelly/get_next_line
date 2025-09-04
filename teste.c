char	*get_next_line(int fd)
{
    static char    *rest;
    char    buffer[BUFFER_SIZE];
    char    *line;
    int bytes_read;
    
    line = NULL;
    bytes_read = 1;
    while (line == NULL && bytes_read != 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
            return (NULL);
        buffer[bytes_read] = '\0';
        line = find_line_breaker(&rest, buffer, bytes_read);
        if (!rest)
            return (NULL);
    }
    if (line)
        return (line);
    if (rest)
    {
        line = find_line_breaker(&rest, NULL, 0);
        return (line);
    }
    return (NULL);
}

char    *find_line_breaker(char **rest, char *buffer, int buffer_len)
{
    char    *line;
    int i;

    i = 0;
    if (*rest)
        line = get_rest_line(*rest, buffer);
    else
    {
        if (buffer != NULL)
        {
            while (buffer[i] && buffer[i] != '\n')
                i++;
            if (buffer[i] == '\n')
            {
                line = ft_strdup(buffer, i + 1);
                i++;
            }
            else
                i = 0;
            *rest = update_rest(*rest, &buffer[i], &line, 0);
        }
        else
            return (NULL);
    }
    return (line);
}

char    *get_rest_line(char **rest, char *buffer)
{
    char    *line;
    int i;

    i = 0;
    if (buffer == NULL)
    {
        line = ft_strdup(*rest, ft_strlen(*rest));
        free (*rest);
        *rest = NULL;
        return (line);
    }
    while ((*rest)[i] != '\n' && (*rest)[i])
        i++;
    if ((*rest)[i] == '\n')
    {
        line = ft_strdup(*rest, i + 1);
        i++;
    }
    else
        i = 0;
    *rest = update_rest(*rest, buffer, &line, i);
    return (line);
}

char    *update_rest(char **rest, char *buffer, char **line, int i)
{
    char    *new_rest;

    if (*rest)
    {
        new_rest = ft_strjoin(*rest + i, buffer);
        free (*rest);
    }
    else
        new_rest = ft_strdup(buffer, ft_strlen(buffer));
    if (!new_rest)
    {
        free (*line);
        *line = NULL;
    }
    return (new_rest);
}
