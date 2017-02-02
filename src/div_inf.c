/*
** div_inf.c for mult_inf in /home/maudit/CPool_bistro-matic
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Wed Nov 02 18:43:11 2016 Gwendal Bazin
** Last update Sun Nov 06 23:07:24 2016 Gwendal Bazin
*/

#include "my.h"
#include "bistro-matic.h"
#include <stdio.h>
#include <stdlib.h>

int	res_fast(t_op *div, char c, ssize_t size, char *nb1)
{
  ssize_t	i;

  i = -1;
  if ((div->res = malloc(sizeof(char) * size)) == NULL)
    exit(put_error(ERROR_MSG, EXIT_MALLOC));
  if (size == 2)
    div->res[0] = c;
  else
    {
      while (++i < size)
	div->res[i] = nb1[i];
    }
  div->res[size - 1] = '\0';
  return (1);
}

int	init_div(t_op *div, char *nb1, char *nb2, char *base)
{
  if (nb2[0] == base[0] && my_strlen(nb2) == 1)
    exit(put_error(ERROR_MSG, EXIT_USAGE));
  else if (nb_cmp(nb1, nb2, base) == 0)
    return (res_fast(div, base[1], 2, nb1));
  else if ((nb1[0] == base[0] && my_strlen(nb1) == 1)
	   || nb_cmp(nb2, nb1, base) > 0)
    return (res_fast(div, base[0], 2, nb1));
  else if (nb2[0] == base[1] && my_strlen(nb2) == 1)
    return (res_fast(div, base[0], (my_strlen(nb1) + 1), nb1));
  else
    {
      div->nb1 = nb1;
      div->nb2 = nb2;
      div->cnt[1] = my_strlen(nb1) - 1;
      div->cnt[2] = my_strlen(nb2) - 1;
    }
  return (0);
}

void	init_digits(t_op *div, char **r, char *base)
{
  ssize_t	i;

  i = -1;
  if ((*r = malloc(sizeof(char) * (div->cnt[1] + 2))) == NULL)
    exit(put_error(ERROR_MSG, EXIT_MALLOC));
  while (div->nb1[++i] != '\0')
    (*r)[i] = div->nb1[i];
  (*r)[i] = '\0';
  if ((div->res = malloc(sizeof(char) * 2)) == NULL)
    exit(put_error(ERROR_MSG, EXIT_MALLOC));
  div->res[0] = base[0];
  div->res[1] = '\0';
}

char	*div_inf(char *nb1, char *nb2, char *base)
{
  t_op	div;
  char	*r;

  if (init_div(&div, nb1, nb2, base) == 1)
    return (div.res);
  init_digits(&div, &r, base);
  while (nb_cmp(r, nb2, base) >= 0)
    {
      r = sub_inf(r, nb2, base);
      div.res = add_inf(div.res, "1", base);
    }
  return (div.res);
}
