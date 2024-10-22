# Get Next Line

The **get_next_line** is the second 42school project. It is a function written in C that reads a line from a file descriptor and returns it.
This project is designed to handle repeated calls, reading one line at a time, and managing variable buffer sizes.
It is a fundamental exercise in file handling and memory management in C, as it requires us to run the function with Valgrind, ensuring that no memory leaks occur.

## Function Overview

- **Function Name**: `get_next_line`
- **Prototype**: `char *get_next_line(int fd);`
- **Parameters**: 
  - `fd`: The file descriptor from which to read.
- **Return Value**: 
  - A string representing the line read, including the newline character (`\n`).
  - Returns `NULL` if there is nothing else to read or if an error occurs.

## Key Features

- **Single Line Reading**: The function returns one line at a time from the file or input source, making it ideal for reading large files without loading the entire content into memory.
- **Newline Handling**: Each line returned includes the terminating newline character (`\n`), except for the last line if it doesn't end with one.
- **Buffer Size Flexibility**: The buffer size for reading can be defined at compile time using the `BUFFER_SIZE` macro (e.g., `-D BUFFER_SIZE=42`). This allows for testing the function with different buffer sizes.
- **Static Variable**: The use of a static variable enables the function to retain information between function calls, allowing it to continue reading from where it left off in the previous call.
- **Memory Management**: The function dynamically allocates memory using `malloc` and frees it when no longer needed, ensuring efficient memory usage.

## Project Restrictions

- **Forbidden Functions**: The use of `lseek()` is not allowed, and using global variables is forbidden. Additionally, the use of our own `libft` library is prohibited in this project.
- **Binary File Behavior**: The function is not expected to handle binary files consistently, but a logical approach can be implemented if desired.

## Compilation

To compile the project, use the following command (example with a buffer size of 42):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
