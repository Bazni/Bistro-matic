/*
** calculate.c for calculate in /home/maxime.gravier/CPool_bistro-maticMG
**
** Made by maxime gravier
** Login   <maxime.gravier@epitech.net>
**
** Started on  Fri Nov  4 15:48:32 2016 maxime gravier
** Last update Sun Nov  6 22:40:22 2016 maxime gravier
*/

#include "bistro-matic.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

ssize_t		cnt_nodes(t_nbr *nb, char *npi)
{
  ssize_t	i;
  ssize_t	nb_els;

  i = nb_els = 0;
  i = 0;
  while (i < (nb->len_npi + 2))
    {
      if (npi[i] == '\0')
	nb_els++;
      i++;
    }
  return (nb_els);
}

void	match_ope(t_nbr *nb, char *ops)
{
  char	*tmp_res;

  if (nb->op->op == ops[PLUS])
    tmp_res = add_inf(nb->nb1->nb, nb->nb2->nb, nb->base);
  else if (nb->op->op == ops[SUB])
    tmp_res = sub_inf(nb->nb1->nb, nb->nb2->nb, nb->base);
  else if (nb->op->op == ops[MULT])
    tmp_res = mult_inf(nb->nb1->nb, nb->nb2->nb, nb->base);
  else if (nb->op->op == ops[DIV])
    tmp_res = div_inf(nb->nb1->nb, nb->nb2->nb, nb->base);
  else if (nb->op->op == ops[MOD])
    tmp_res = mod_inf(nb->nb1->nb, nb->nb2->nb, nb->base);
  empty_npi_l(nb, tmp_res);
}

void	init_calc(t_nbr *nb, char **av, t_npi_l **npi_l)
{
  nb->res = NULL;
  nb->base = av[1];
  if ((*npi_l = malloc(sizeof(t_npi_l))) == NULL)
    exit(put_error(ERROR_MSG, EXIT_MALLOC));
  (*npi_l)->next = NULL;
}

ssize_t		get_len_list(t_npi_l **begin)
{
  ssize_t	len;
  t_npi_l	*tmp;

  len = 0;
  tmp = *begin;
  while (tmp->next != NULL)
    {
      len++;
      tmp = tmp->next;
    }
  return (len);
}

char	*calculate(char *expr, char **av)
{
  t_nbr		nb;
  char		*npi;
  t_npi_l	*npi_l;
  ssize_t	nb_nodes;

  nb.len_npi = npi_transform(expr, &npi, av[1], av[2]);
  nb.len_npi = nb.len_npi - 2;
  nb_nodes = cnt_nodes(&nb, npi);
  init_calc(&nb, av, &npi_l);
  while (nb_nodes > 0)
    {
      add_node(&npi_l, npi, &nb, av[2]);
      nb_nodes--;
    }
  nb.begin = npi_l;
  while (get_len_list(&(nb.begin)) >= 3)
    {
      nb.op = get_op(&npi_l, av[2]);
      get_nb(&nb);
      match_ope(&nb, av[2]);
    }
  nb.res = nb.op->nb;
  return (nb.res);
}
