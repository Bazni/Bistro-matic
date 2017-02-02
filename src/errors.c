/*
** errors.c for bistro-matic in /home/thomas.couacault/rendu/CPool_bistro-matic
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Mon Oct 31 09:28:20 2016 Thomas Couacault
** Last update Sun Nov  6 23:36:05 2016 maxime gravier
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "bistro-matic.h"
#include "my.h"

int	put_error(char *str, int num_error)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
	i++;
    }
  return (num_error);
}

void	d_char_in_base(char **av)
{
  int	i;
  int	j;

  i = -1;
  while (i++ < my_strlen(av[1]))
    {
      j = i + 1;
      while (av[1][j] != '\0')
	{
	  if (av[1][i] == av[1][j])
	    exit(put_error(SYNTAX_ERROR_MSG, EXIT_BASE));
	  j++;
	}
    }
  i = -1;
  while (i++ < 7)
    {
      j = i + 1;
      while (av[2][j] != '\0')
	{
	  if (av[2][i] == av[2][j])
	    exit(put_error(SYNTAX_ERROR_MSG, EXIT_BASE));
	  j++;
	}
    }
}

void	char_in_both_base(char *base_nb, char *base_op)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = my_strlen(base_nb);
  while (i < k)
    {
      while (base_op[j] != '\0')
	{
	  if (base_nb[i] == base_op[j])
	    exit(put_error(SYNTAX_ERROR_MSG, EXIT_BASE));
	  j++;
	}
      j = 0;
      i++;
    }
}

void	ope_first(int i, int p, char *expr, char **av)
{
  if (expr[i] != av[2][OPEN_PARENT] && expr[i] != av[2][SUB])
    exit(put_error(SYNTAX_ERROR_MSG, EXIT_OPS));
  else
    {
      if (expr[i + 1] == '\0')
	exit(put_error(SYNTAX_ERROR_MSG, EXIT_OPS));
      check_operator(i, p, expr, av);
    }
}

void	expr_errors(char *expr, char **av)
{
  int	i;
  int	p;

  i = -1;
  p = 0;
  d_char_in_base(av);
  char_in_both_base(av[1], av[2]);
  only_spaces(i, expr, av);
  i = -1;
  while (expr[++i] != '\0')
    {
      if (is_in_base(expr[i], av[1]) == 0 && is_in_base(expr[i], av[2]) == 0)
	{
	  (expr[i] == ' ') ? check_space(i, expr, av)
	    : exit(put_error(SYNTAX_ERROR_MSG, EXIT_BASE));
	}
      if (is_in_base(expr[i], av[2]) == 1 && i == 0)
	ope_first(i, p, expr, av);
      if (is_in_base(expr[i], av[1]) == 1)
	check_number(i, expr, av);
      if (is_in_base(expr[i], av[2]) == 1)
	p = check_operator(i, p, expr, av);
    }
  if (p != 0)
    exit(put_error(SYNTAX_ERROR_MSG, EXIT_PARENT));
}
