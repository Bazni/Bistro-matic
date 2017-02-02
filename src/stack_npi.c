/*
** stack.c for bistro-matic in /home/thomas.couacault/rendu/CPool_bistro-matic
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Tue Nov  1 12:02:31 2016 Thomas Couacault
** Last update Sun Nov  6 22:06:38 2016 maxime gravier
*/

#include "my.h"
#include "bistro-matic.h"
#include <stdio.h>
#include <stdlib.h>

void		add_paren_in_stack(t_stack **list, char c)
{
  t_stack	*element;

  if ((element = malloc(sizeof(*element))) == NULL)
    exit(put_error(ERROR_MSG, EXIT_MALLOC));
  element->op = c;
  element->next = *list;
  *list = element;
}

void		add_op_in_stack(t_stack **list, char op, char *ops)
{
  t_stack	*element;

  if (is_in_ops(op, ops))
    {
      if ((element = malloc(sizeof(*element))) == NULL)
	exit(put_error(ERROR_MSG, EXIT_MALLOC));
      element->op = op;
      element->next = *list;
      *list = element;
    }
}

void		suppr_stack(t_stack **stack)
{
  t_stack	*tmp;

  tmp = *stack;
  *stack = tmp->next;
  free(tmp);
}

void		empty_stack(t_stack **stack, t_npi *s_npi)
{
  t_stack	*tmp;

  tmp = (*stack);
  while (tmp != NULL)
    {
      add_op_npi(stack, s_npi);
      suppr_stack(stack);
      tmp = tmp->next;
    }
}
