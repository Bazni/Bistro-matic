/*
** npi_list.c for calculate in /home/maxime.gravier/CPool_bistro-maticMG
**
** Made by thomas.couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Fri Nov  4 15:48:32 2016 Thomas Couacault
** Last update Sun Nov 06 23:30:59 2016 Gwendal Bazin
*/

#include "bistro-matic.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	del_node(t_npi_l **to_del)
{
  t_npi_l	*tmp;

  tmp = *to_del;
  if (tmp->prev == NULL)
    {
      (*to_del) = (*to_del)->next;
      (*to_del)->prev = NULL;
    }
  else
    {
      (*to_del)->prev->next = (*to_del)->next;
      (*to_del)->next->prev = (*to_del)->prev;
    }
  free(tmp);
}

ssize_t		rev_strlen(char *str, ssize_t begin)
{
  ssize_t	len;

  len = begin;
  while (str[len] != '\0')
    len--;
  return (begin - len);
}

void	init_node(t_npi_l **node, t_npi_l **npi_l, ssize_t *i)
{
  if ((*node = malloc(sizeof(t_npi_l))) == NULL)
    exit(put_error(ERROR_MSG, EXIT_MALLOC));
  (*npi_l)->prev = *node;
  (*node)->next = *npi_l;
  (*node)->prev = NULL;
  *npi_l = *node;
  *i = 0;
}

void	add_node(t_npi_l **npi_l, char *npi, t_nbr *nb, char *ops)
{
  t_npi_l	*node;
  ssize_t	i;

  init_node(&node, npi_l, &i);
  if (is_in_ops(npi[nb->len_npi], ops))
    {
      node->op = npi[nb->len_npi];
      node->nb = NULL;
      nb->len_npi = nb->len_npi - 2;
    }
  else if (is_in_base(npi[nb->len_npi], nb->base))
    {
      if ((node->nb = malloc(sizeof(char) *
			     (rev_strlen(npi, nb->len_npi) + 1))) == NULL)
	exit(put_error(ERROR_MSG, EXIT_MALLOC));
      node->nb[rev_strlen(npi, nb->len_npi)] = '\0';
      while (npi[nb->len_npi] != '\0')
	{
	  node->nb[i++] = npi[nb->len_npi];
	  nb->len_npi = nb->len_npi - 1;
	}
      nb->len_npi = nb->len_npi - 1;
      node->nb = my_revstr(node->nb);
      node->op = '\0';
    }
}

void	empty_npi_l(t_nbr *nb, char *res)
{
  ssize_t	i;

  i = -1;
  if (nb->nb1->prev != NULL)
    nb->begin = nb->nb1->prev;
  else
    nb->begin = nb->op;
  del_node(&(nb->nb1));
  del_node(&(nb->nb2));
  nb->op->op = '\0';
  if ((nb->op->nb = malloc(sizeof(char) * (my_strlen(res) + 1))) == NULL)
    exit(put_error(ERROR_MSG, EXIT_MALLOC));
  nb->op->nb[my_strlen(res)] = '\0';
  while (++i < my_strlen(res))
    nb->op->nb[i] = res[i];
}
