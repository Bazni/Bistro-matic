##
## Makefile for infinadd in /home/thomas.couacault/CPool_infinadd
##
## Made by Thomas Couacault
## Login   <thomas.couacault@epitech.net>
##
## Started on  Mon Oct 24 10:05:26 2016 Thomas Couacault
## Last update Thu Feb  2 16:22:57 2017 Gwendal Bazin
##

CFLAGS	+=	-Wall -Wextra -Wpedantic
CFLAGS	+=	-Iinclude -g

CC	=	gcc

DIR	=	src/

SRC	=	$(DIR)main.c			\
		$(DIR)add_inf.c			\
		$(DIR)checks.c			\
		$(DIR)cmpt_add.c		\
		$(DIR)sub_inf.c			\
		$(DIR)get_calc.c		\
		$(DIR)cmpt_sub.c		\
		$(DIR)mod_inf.c			\
		$(DIR)div_inf.c			\
		$(DIR)mult_inf.c		\
		$(DIR)operations.c		\
		$(DIR)errors.c			\
		$(DIR)npi.c			\
		$(DIR)npi2.c			\
		$(DIR)npi_transform.c		\
		$(DIR)stack_npi.c		\
		$(DIR)man.c			\
		$(DIR)npi_list.c		\
		$(DIR)spaces.c			\
		$(DIR)calculate.c

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) -L./lib/ -lmy

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all
