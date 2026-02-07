NAME = libjr.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/jr_memset.c srcs/jr_bzero.c srcs/jr_memcpy.c srcs/jr_memccpy.c srcs/jr_memmove.c srcs/jr_memcmp.c srcs/jr_atoi.c srcs/jr_isalpha.c srcs/jr_isdigit.c srcs/jr_isalnum.c srcs/jr_isascii.c srcs/jr_isprint.c srcs/jr_toupper.c srcs/jr_tolower.c srcs/jr_memdel.c srcs/jr_strnew.c srcs/jr_strdel.c srcs/jr_strclr.c srcs/jr_striter.c srcs/jr_striteri.c srcs/jr_strmap.c srcs/jr_strmapi.c srcs/jr_strequ.c srcs/jr_strnequ.c srcs/jr_strsub.c srcs/jr_strjoin.c srcs/jr_strtrim.c srcs/jr_strsplit.c srcs/jr_itoa.c srcs/jr_putchar.c srcs/jr_putstr.c srcs/jr_putendl.c srcs/jr_putnbr.c srcs/jr_strlen.c srcs/jr_lstnew.c srcs/jr_calloc.c

OBJS = $(SRCS:.c=.o)

INCLUDES = includes

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

