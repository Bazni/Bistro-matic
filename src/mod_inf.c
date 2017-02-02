/*
** mod_inf.c for mult_inf in /home/maudit/CPool_bistro-matic
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Wed Nov 02 18:43:11 2016 Thomas Couacault
** Last update Sun Nov 06 23:07:52 2016 Gwendal Bazin
*/

#include "my.h"
#include "bistro-matic.h"
#include <stdio.h>
#include <stdlib.h>

int	res_fast_mod(t_op *mod, char c, ssize_t size, char *nb1)
{
  ssize_t	i;

  i = -1;
  if ((mod->res = malloc(sizeof(char) * size)) == NULL)
    exit(put_error(ERROR_MSG, EXIT_MALLOC));
  if (size == 2)
    mod->res[0] = c;
  else
    {
      while (++i < size)
	mod->res[i] = nb1[i];
    }
  mod->res[size - 1] = '\0';
  return (1);
}

int	init_mod(t_op *mod, char *nb1, char *nb2, char *base)
{
  if (nb2[0] == base[0] && my_strlen(nb2) == 1)
    exit(put_error(ERROR_MSG, EXIT_USAGE));
  else if (nb_cmp(nb1, nb2, base) == 0)
    return (res_fast_mod(mod, base[1], 2, nb1));
  else if ((nb1[0] == base[0] && my_strlen(nb1) == 1)
	   || nb_cmp(nb2, nb1, base) > 0)
    return (res_fast_mod(mod, base[0], 2, nb1));
  else if (nb2[0] == base[1] && my_strlen(nb2) == 1)
    return (res_fast_mod(mod, base[0], (my_strlen(nb1) + 1), nb1));
  if (nb_cmp(nb1, nb2, base) == 0 || nb1[0] == base[0])
    {
      mod->res = malloc(sizeof(char) *  2);
      mod->res[1] = '\0';
      mod->res[0] = base[0];
      return (0);
    }
  else
    {
      mod->nb1 = nb1;
      mod->nb2 = nb2;
      mod->cnt[1] = my_strlen(nb1) - 1;
      mod->cnt[2] = my_strlen(nb2) - 1;
    }
  return (0);
}

void	init_digits_mod(t_op *mod, char **r, char *base)
{
  ssize_t	i;

  i = -1;
  if ((*r = malloc(sizeof(char) * (mod->cnt[1] + 2))) == NULL)
    exit(put_error(ERROR_MSG, EXIT_MALLOC));
  while (mod->nb1[++i] != '\0')
    (*r)[i] = mod->nb1[i];
  (*r)[i] = '\0';
  if ((mod->res = malloc(sizeof(char) * 2)) == NULL)
    exit(put_error(ERROR_MSG, EXIT_MALLOC));
  mod->res[0] = base[0];
  mod->res[1] = '\0';
}

char	*mod_inf(char *nb1, char *nb2, char *base)
{
  t_op	mod;
  char	*r;

  if (init_mod(&mod, nb1, nb2, base) == 1)
    return (mod.res);
  init_digits_mod(&mod, &r, base);
  while (nb_cmp(r, nb2, base) >= 0)
    {
      r = sub_inf(r, nb2, base);
      mod.res = add_inf(mod.res, "1", base);
    }
  return (r);
}
