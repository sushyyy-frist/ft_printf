NAME = libftprintf.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c ft_putchar.c ft_puthexa_lower.c ft_puthexa_upper.c \
			ft_putnbr.c ft_putptr.c ft_putstr.c ft_putunsigned.c
OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJECTS)
 
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re 