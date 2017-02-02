/*
** npi_transform.c for bistro-matic in /home/thomas.couacault/rendu/CPool_bistro-matic
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Mon Oct 31 15:04:51 2016 Thomas Couacault
** Last update Thu Nov  3 10:34:09 2016 Thomas Couacault
*/

#include "my.h"
#include "bistro-matic.h"
#include <stdio.h>
#include <stdlib.h>

void	add_nb_npi(t_npi *s_npi, char *base)
{
  while (is_in_base(s_npi->expr[s_npi->cnt[0]], base))
    {
      (s_npi->npi)[0][s_npi->cnt[1]] = s_npi->expr[s_npi->cnt[0]];
      s_npi->cnt[1] = s_npi->cnt[1] + 1;
      s_npi->cnt[0] = s_npi->cnt[0] + 1;
    }
  s_npi->cnt[1] = s_npi->cnt[1] + 1;
  s_npi->cnt[0] = s_npi->cnt[0] - 1;
}

void	add_op_npi(t_stack **stack, t_npi *s_npi)
{
  s_npi->npi[0][s_npi->cnt[1]] = (*stack)->op;
  (*stack)->op = s_npi->expr[s_npi->cnt[0]];
  s_npi->cnt[1] = s_npi->cnt[1] + 2;
}

ssize_t		get_len_npi(char *expr, char *base, char *ops)
{
  ssize_t	chars;
  ssize_t	strings;

  chars = nb_chars(expr, base, ops);
  strings = nb_strings(expr, base, ops);
  return (chars + strings);
}
