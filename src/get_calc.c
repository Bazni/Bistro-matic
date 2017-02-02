/*
** calculate.c for calculate in /home/maxime.gravier/CPool_bistro-maticMG
**
** Made by maxime gravier
** Login   <maxime.gravier@epitech.net>
**
** Started on  Fri Nov  4 15:48:32 2016 maxime gravier
** Last update Sat Nov 05 18:16:03 2016 Gwendal Bazin
*/

#include "bistro-matic.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

t_npi_l		*get_op(t_npi_l	**npi_l, char *ops)
{
  t_npi_l	*op;
  t_npi_l	*tmp;
  ssize_t	i;

  i = 0;
  tmp = *npi_l;
  while (tmp->next != NULL && i == 0)
    {
      if (is_in_ops(tmp->op, ops))
	i = 1;
      tmp = tmp->next;
    }
  op = tmp->prev;
  return (op);
}

void	get_nb(t_nbr *nb)
{
  t_npi_l	*tmp;
  ssize_t	i;

  i = 1;
  tmp = nb->op->prev;
  while (tmp->op == '\0' && i < 2)
    {
      tmp = tmp->prev;
      i++;
    }
  nb->nb1 = tmp;
  if (i == 2)
    nb->nb2 = tmp->next;
  else if (i == 1)
    nb->nb2 = NULL;
}
