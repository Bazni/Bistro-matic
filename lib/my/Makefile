##
## Makefile for D10 in /home/thomas.couacault/CPool_Day10/lib/my
##
## Made by Thomas Couacault
## Login   <thomas.couacault@epitech.net>
##
## Started on  Fri Oct 14 10:05:26 2016 Thomas Couacault
## Last update Mon Oct 31 13:49:08 2016 maxime gravier
##

AUTEUR	=	thomas.couacault@epitech.eu

SRC	=	my_find_prime_sup.c	\
		my_atoi.c		\
		my_isneg.c		\
		my_is_prime.c		\
		my_power_rec.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_showmem.c		\
		my_showstr.c		\
		my_show_wordtab.c	\
		my_sort_int_tab.c	\
		my_square_root.c	\
		my_strcapitalize.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c		\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_str_to_wordtab.c	\
		my_strupcase.c		\
		my_swap.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)	copy	clean

$(NAME):	$(SRC)	$(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)

copy:
	cp $(NAME) ../
	cp my.h ../../include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

auteur:
	echo $(AUTEUR) > ../../auteur
