# Libft

Libft is a custom implementation of standard C library functions, designed for educational purposes and to provide a foundation for future C projects. This library includes a variety of functions for string manipulation, memory management, character checks, linked list operations, and more.

## Features
- Character checks: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- String manipulation: `ft_strlen`, `ft_strcpy`, `ft_strcat`, `ft_strdup`, `ft_strncmp`, `ft_strchr`, `ft_strrchr`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_substr`, `ft_strmapi`, `ft_striteri`
- Memory management: `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_bzero`, `ft_calloc`
- Conversion: `ft_atoi`, `ft_itoa`, `ft_basetoi`, `ft_tolower`, `ft_toupper`
- Linked list operations: `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstlast`, `ft_lstsize`, `ft_lstmap`
- Output functions: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

## Directory Structure
```
include/
    libft.h
src/
    ft_is/
    ft_lst/
    ft_mem/
    ft_put/
    ft_str/
    ft_to/
Makefile
```

## Usage
1. Clone the repository:
   ```sh
   git clone https://github.com/Denionline/Libft.git
   cd Libft
   ```
2. Build the library:
   ```sh
   make
   ```
3. Include `libft.h` in your project and link with the compiled library.

## License
This project is for educational purposes and does not have a specific license.

## Author
Denionline
