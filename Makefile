NAME = get_next_line

CC = cc

CFLAGS = -Wextra -Werror -Wall

SRCS = get_next_line.c get_next_line_utils.c

HEADER = "get_next_line.h"

all : $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) 
