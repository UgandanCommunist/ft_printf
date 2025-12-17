NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_unsigned.c \
      ft_puthex_low.c ft_puthex_high.c ft_putpointer.c
OBJ = $(SRC:.c=.o)

%.o: %.c printlib.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
