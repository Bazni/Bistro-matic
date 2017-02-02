/*
** checks.c for checks in /home/maxime.gravier/CPool_bistro-maticMG/Errors
**
** Made by maxime gravier
** Login   <maxime.gravier@epitech.net>
**
** Started on  Sat Nov  5 18:55:06 2016 maxime gravier
** Last update Sun Nov  6 16:47:31 2016 maxime gravier
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bistro-matic.h"

void	check_space(int i, char *expr, char **av)
{
  if (is_in_base(expr[i - 1], av[1]) == 1)
    {
      if (is_in_base(expr[i + 1], av[1]) == 1)
	exit(put_error(SYNTAX_ERROR_MSG, EXIT_SPACE));
      if (expr[i + 1] == av[2][OPEN_PARENT])
	exit(put_error(SYNTAX_ERROR_MSG, EXIT_SPACE));
    }
  if (is_in_base(expr[i - 1], av[2]) == 1)
    {
      if (expr[i - 1] == av[2][OPEN_PARENT]
	  && expr[i + 1] == av[2][CLOSE_PARENT])
	exit(put_error(SYNTAX_ERROR_MSG, EXIT_SPACE));
      else if (expr[i - 1] == av[2][CLOSE_PARENT]
	       && is_in_base(expr[i + 1], av[1]) == 1)
	exit(put_error(SYNTAX_ERROR_MSG, EXIT_SPACE));
      else
	{
	  if (expr[i - 1] == av[2][OPEN_PARENT]
	      && is_in_base(expr[i + 1], av[2]) == 1)
	    exit(put_error(SYNTAX_ERROR_MSG, EXIT_PARENT));
	}
    }
}

void	check_number(int i, char *expr, char **av)
{
  if (expr[i + 1] == av[2][OPEN_PARENT])
    exit(put_error(SYNTAX_ERROR_MSG, EXIT_NUMBER));
}

int	check_open(int i, int p, char *expr, char **av)
{
  p++;
  if (is_in_base(expr[i + 1], av[2]) == 1)
    {
      if (expr[i + 1] != av[2][SUB] && expr[i + 1] != av[2][OPEN_PARENT])
	exit(put_error(SYNTAX_ERROR_MSG, EXIT_PARENT));
    }
  return (p);
}

int	check_close(int i, int p, char *expr, char **av)
{
  p--;
  if (is_in_base(expr[i + 1], av[1]) == 1)
    exit(put_error(SYNTAX_ERROR_MSG, EXIT_PARENT));
  if (expr[i + 1] == av[2][OPEN_PARENT] && expr[i + 1] != '\0')
    exit(put_error(SYNTAX_ERROR_MSG, EXIT_PARENT));
  return (p);
}

int	check_operator(int i, int p, char *expr, char **av)
{
  if (expr[i] == av[2][OPEN_PARENT])
    p = check_open(i, p, expr, av);
  else if (expr[i] == av[2][CLOSE_PARENT])
    p = check_close(i, p, expr, av);
  else
    {
      if (is_in_base(expr[i + 1], av[2]) == 1)
	{
	  if (expr[i] == av[2][SUB] || expr[i] == av[2][PLUS])
	    {
	      if (expr[i + 1] != av[2][OPEN_PARENT]
		  && expr[i + 1] != av[2][SUB] && expr[i + 1] != av[2][PLUS])
	      exit(put_error(SYNTAX_ERROR_MSG, EXIT_OPS));
	    }
	  else if (expr[i + 1] != av[2][SUB]
		   && expr[i + 1] != av[2][OPEN_PARENT])
	    exit(put_error(SYNTAX_ERROR_MSG, EXIT_OPS));
	}
    }
  if (p < 0)
    exit(put_error(SYNTAX_ERROR_MSG, EXIT_PARENT));
  return (p);
}
