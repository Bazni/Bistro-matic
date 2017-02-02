/*
** npi_transform.c for bistro-matic in /home/thomas.couacault/rendu/CPool_bistro-matic
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Mon Oct 31 15:04:51 2016 Thomas Couacault
** Last update Sun Nov 06 23:23:39 2016 Gwendal Bazin
*/

#include "my.h"
#include "bistro-matic.h"
#include <stdio.h>
#include <stdlib.h>

void	handle_paren_cl(t_stack **stack, t_npi *s_npi, char *ops)
{
  t_stack       *tmp;

  tmp = (*stack);
  while (tmp->op != ops[OPEN_PARENT])
    {
      add_op_npi(stack, s_npi);
      tmp = tmp->next;
      suppr_stack(&(*stack));
    }
  suppr_stack(&(*stack));
}

void	handle_op(t_stack **stack, t_npi *s_npi, char *ops)
{
  if (s_npi->expr[s_npi->cnt[0]] == '-'
      && s_npi->expr[s_npi->cnt[0] - 1] == ops[OPEN_PARENT])
    s_npi->cnt[0] = s_npi->cnt[0];
  else
    {
      if (*stack == NULL)
	add_op_in_stack(stack, s_npi->expr[s_npi->cnt[0]], ops);
      else if ((*stack)->op == ops[OPEN_PARENT])
	add_op_in_stack(stack, s_npi->expr[s_npi->cnt[0]], ops);
      else if (prio_op(s_npi->expr[s_npi->cnt[0]]) > prio_op((*stack)->op))
	add_op_in_stack(stack, s_npi->expr[s_npi->cnt[0]], ops);
      else
	add_op_npi(stack, s_npi);
    }
}

void	init_npi(t_npi *s_npi, char *expr, char **npi)
{
  ssize_t	i;

  i = 0;
  s_npi->npi = npi;
  if (((s_npi->npi)[0] = malloc(sizeof(char) * s_npi->len)) == NULL)
    exit(put_error(ERROR_MSG, EXIT_MALLOC));
  while (i < s_npi->len)
    {
      (s_npi->npi)[0][i] = '\0';
      i++;
    }
  s_npi->cnt[0] = 0;
  s_npi->cnt[1] = 0;
  s_npi->expr = expr;
}

ssize_t		npi_transform(char *expr, char **npi, char *base, char *ops)
{
  t_stack	*stack;
  t_npi		s_npi;

  s_npi.len = get_len_npi(expr, base, ops);
  init_npi(&s_npi, expr, npi);
  stack = NULL;
  while (expr[s_npi.cnt[0]] != '\0')
    {
      if (is_in_base(expr[s_npi.cnt[0]], base))
	add_nb_npi(&s_npi, base);
      else if (expr[s_npi.cnt[0]] == ops[OPEN_PARENT])
	add_paren_in_stack(&stack, expr[s_npi.cnt[0]]);
      else if (is_in_ops(expr[s_npi.cnt[0]], ops))
	handle_op(&stack, &s_npi, ops);
      else if (expr[s_npi.cnt[0]] == ops[CLOSE_PARENT])
	handle_paren_cl(&stack, &s_npi, ops);
      s_npi.cnt[0] = s_npi.cnt[0] + 1;
    }
  empty_stack(&stack, &s_npi);
  return (s_npi.len);
}
