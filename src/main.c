/*
** main.c for bistro-matic in /home/maxime.gravier/CPool_bistro-matic
**
** Made by maxime gravier
** Login   <maxime.gravier@epitech.net>
**
** Started on  Mon Oct 31 11:38:27 2016 maxime gravier
** Last update Sun Nov  6 18:31:13 2016 maxime gravier
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "bistro-matic.h"
#include "my.h"

static	char	*get_expr(unsigned int size)
{
  char	*expr;

  if (size <= 0)
    exit(put_error(SYNTAX_ERROR_MSG, EXIT_SIZE_NEG));
  if ((expr = malloc(size + 1)) == NULL)
    exit(put_error(ERROR_MSG, EXIT_MALLOC));
  if (read(0, expr, size) != size)
    exit(put_error(ERROR_MSG, EXIT_READ));
  expr[size] = '\0';
  return (expr);
}

static	void	check_base(char *b)
{
  if (my_strlen(b) < 2)
    exit(put_error(SYNTAX_ERROR_MSG, EXIT_BASE));
}

static	void	check_ops(char *ops)
{
  if (my_strlen(ops) != 7)
    exit(put_error(SYNTAX_ERROR_MSG, EXIT_OPS));
}

int	main(int ac, char **av)
{
  char	*expr;
  unsigned int	size;

  if (ac != 4)
    {
      my_putstr("Usage: ");
      my_putstr(av[0]);
      my_putstr(" base ops \"()+-*/%\" exp_len\n");
      return (EXIT_USAGE);
    }
  man(av[1]);
  check_base(av[1]);
  check_ops(av[2]);
  size = my_atoi(av[3]);
  expr = get_expr(size);
  expr_errors(expr, av);
  my_putstr(calculate(expr, av));
  return (EXIT_SUCCESS);
}
