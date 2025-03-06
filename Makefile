##
## EPITECH PROJECT, 2024
## test
## File description:
## test
##

NAME	=	setting_up

LIB_NAME	=	libmy.a

SRC	=	src/main.c	\
		src/error_handling.c	\
		src/get_map.c	\
		src/solver.c	\

LIB_SRC	=	lib/my/my_compute_power_rec.c	\
		lib/my/my_compute_square_root.c	\
		lib/my/my_find_prime_sup.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_isneg.c	\
		lib/my/my_is_prime.c	\
		lib/my/my_putchar.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putstr.c	\
		lib/my/my_putstrerr.c	\
		lib/my/my_revstr.c	\
		lib/my/my_sort_int_array.c	\
		lib/my/my_strcapitalize.c	\
		lib/my/my_strcat.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_strcpy.c	\
		lib/my/my_str_isalpha.c	\
		lib/my/my_str_islower.c	\
		lib/my/my_str_isnum.c	\
		lib/my/my_str_isprintable.c	\
		lib/my/my_str_isupper.c	\
		lib/my/my_strlen.c	\
		lib/my/my_strlowcase.c	\
		lib/my/my_strncat.c	\
		lib/my/my_strncmp.c	\
		lib/my/my_strncpy.c	\
		lib/my/my_strstr.c	\
		lib/my/my_strupcase.c	\
		lib/my/my_swap.c	\
		lib/my/my_intlen.c

OBJ	=	$(SRC:.c=.o)

LIB_OBJ	=	$(LIB_SRC:.c=.o)

CFLAGS	=	-Iinclude/ -Wall -Wextra

all: $(LIB_NAME) $(NAME)

$(LIB_NAME):	$(LIB_OBJ)
	ar rc lib/my/$(LIB_NAME) $(LIB_OBJ)

$(NAME):	$(SRC)
	gcc -o $(NAME) $(SRC) $(CFLAGS) -Llib/my/ -lmy

clean:
	rm -f $(LIB_OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f lib/my/$(LIB_NAME)

re: fclean all
