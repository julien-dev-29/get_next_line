NAME = get_next_line
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c get_next_line.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -Iincludes
LIBS = -L. -ljr  

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
