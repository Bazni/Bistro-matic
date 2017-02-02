/*
** npi.c for bistro-matic in /home/thomas.couacault/rendu/CPool_bistro-matic
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Mon Oct 31 15:04:51 2016 Thomas Couacault
** Last update Thu Nov  3 10:19:01 2016 John Doe
*/

#include "bistro-matic.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int	nb_chars(char *expr, char *base, char *ops)
{
  ssize_t	nb;
  ssize_t	i;

  nb = i = 0;
  while (expr[i] != '\0')
    {
      if (is_in_base(expr[i], base) || is_in_ops(expr[i], ops))
	nb++;
      i++;
    }
  return (nb);
}

int	nb_strings(char *expr, char *base, char *ops)
{
  ssize_t	i;
  ssize_t	nb;

  i = 1;
  nb = (is_in_base(expr[0], base)) ? 1 : 0;
  while (expr[i] != '\0')
    {
      if ((is_in_base(expr[i], base) && !is_in_base(expr[i - 1], base))
	  || (is_in_ops(expr[i], ops)))
	nb++;
      i++;
    }
  return (nb);
}

int	prio_op(char c)
{
  if (c == '*' || c == '/' || c == '%')
    return (2);
  else if (c == '+' || c == '-')
    return (1);
  return (0);
}
