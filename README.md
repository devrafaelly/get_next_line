# Get Next Line

A C function that reads a file line by line, allowing you to read a text file one line at a time.

## Table of Contents

- [Overview](#overview)
- [Function Prototype](#function-prototype)
- [Parameters](#parameters)
- [Return Value](#return-value)
- [Compilation](#compilation)
- [Usage](#usage)
- [Bonus Features](#bonus-features)
- [Examples](#examples)
- [Implementation Details](#implementation-details)
- [Testing](#testing)

## Overview

Get Next Line (GNL) is a function that reads a text file and returns one line at a time. This project teaches important concepts about static variables, memory management, and file manipulation in C.

Key features:
- Reads any file descriptor line by line
- Handles files without a final newline
- Memory efficient implementation
- Works with different buffer sizes
- **Bonus**: Can handle multiple file descriptors simultaneously

## Function Prototype

```c
char *get_next_line(int fd);
```

## Parameters

- `fd`: The file descriptor to read from

## Return Value

- **Success**: Returns the line read from the file descriptor, including the terminating `\n` character (except for the last line if it doesn't end with `\n`)
- **End of file**: Returns `NULL` when there's nothing more to read
- **Error**: Returns `NULL` on error (invalid fd, read error, malloc failure)

## Compilation

### Basic Version

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c
```

### With Bonus

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line_bonus.c get_next_line_utils_bonus.c
```

### Files Structure

```
get_next_line/
├── get_next_line.h
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line_bonus.h (bonus)
├── get_next_line_bonus.c (bonus)
└── get_next_line_utils_bonus.c (bonus)
```

## Usage

### Basic Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

### Reading from Standard Input

```c
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *line;
    
    printf("Enter lines (Ctrl+D to end):\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("You entered: %s", line);
        free(line);
    }
    
    return (0);
}
```

## Bonus Features

The bonus version extends functionality to handle **multiple file descriptors simultaneously**.

### Key Differences

- Can read from multiple files at the same time
- Maintains separate static variables for each file descriptor
- Supports up to `MAX_FD` file descriptors (typically 1024)

### Bonus Usage Example

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2;
    char *line1, *line2;
    
    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    if (fd1 == -1 || fd2 == -1)
        return (1);
    while ((line1 = get_next_line(fd1)) != NULL || 
           (line2 = get_next_line(fd2)) != NULL)
    {
        if (line1)
        {
            printf("File1: %s", line1);
            free(line1);
        }
        if (line2)
        {
            printf("File2: %s", line2);
            free(line2);
        }
    }
    close(fd1);
    close(fd2);
    return (0);
}
```

## Examples

### File Content Examples

**example.txt:**
```
Hello World!
This is line 2
Final line without newline
```

**Output:**
```
Hello World!
This is line 2
Final line without newline
```

### Different Buffer Sizes

```bash
# Small buffer size - more system calls
cc -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c

# Large buffer size - fewer system calls
cc -D BUFFER_SIZE=4096 get_next_line.c get_next_line_utils.c

# Default recommended size
cc -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c
```

## Implementation Details

### Core Functions

**get_next_line.c:**
- `get_next_line()` - Main function that returns one line
- Static variable to maintain buffer between calls

**get_next_line_utils.c:**
- `ft_strchr()` - Find character in string
- `ft_substr()` - Extract substring
- `ft_strjoin()` - Join two strings
- `ft_memcpy()` - Copy memory area
- `ft_calloc()` - Allocate and zero memory

### Memory Management

- Always free the returned line after use
- Function handles internal memory management
- No memory leaks when used correctly
- Handles edge cases like empty files and lines

### Buffer Management

- Uses `BUFFER_SIZE` defined either at compilation (`-D BUFFER_SIZE=value`) or in header file
- Maintains remainder in static variable
- Efficiently handles partial reads
- Works with any reasonable buffer size (1 to several MB)

### Error Handling

- Returns `NULL` on invalid file descriptor
- Returns `NULL` on read errors
- Returns `NULL` on malloc failures
- Properly handles closed file descriptors

## Testing

### Test Cases

1. **Basic functionality:**
   - Read normal files with different line lengths
   - Files ending with and without newlines
   - Empty files
   - Single character files

2. **Edge cases:**
   - Invalid file descriptors (-1, closed fd)
   - Very long lines
   - Files with only newlines
   - Binary files

3. **Buffer size variations:**
   - BUFFER_SIZE = 1
   - BUFFER_SIZE = 42
   - BUFFER_SIZE = 1024
   - BUFFER_SIZE = 999999

4. **Bonus testing:**
   - Multiple file descriptors
   - Alternating reads
   - Different file sizes
   - Standard input + files

### Memory Testing

```bash
# Check for memory leaks
valgrind --leak-check=full ./your_program

# Check for invalid reads/writes
valgrind --track-origins=yes ./your_program
```

### Performance Testing

- Test with different buffer sizes
- Large files (several MB)
- Many small files
- Files with very long lines

## Notes

- **No global variables allowed**
- **No libft functions allowed** (implement needed functions in utils)
- Function must work with different `BUFFER_SIZE` values
- Behavior is undefined for binary files
- Only one static variable allowed (bonus: one per fd)
- Must compile without errors with `-Wall -Wextra -Werror`

This project demonstrates proficiency in:
- Static variables and their lifecycle
- Memory management and leak prevention
- File I/O operations
- String manipulation
- Buffer management
- Error handling
