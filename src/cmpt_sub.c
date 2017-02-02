/*
** sub_inf.c for bistro-matic in /home/thomas.couacault/rendu/CPool_bistro-matic
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Tue Nov  1 16:57:39 2016 Thomas Couacault
** Last update Sun Nov 06 23:09:34 2016 Gwendal Bazin
*/

#include "my.h"
#include "bistro-matic.h"
#include <stdio.h>
#include <stdlib.h>

void	compute_sub(t_op *sub, char *base, int *hold)
{
  int		calc;
  ssize_t	limit;

  calc = 0;
  limit = my_strlen(base);
  if (nb_cmp(sub->nb1, sub->nb2, base) >= 0)
    {
      calc = get_index(base, sub->nb1[sub->cnt[1]]);
      calc -= get_index(base, sub->nb2[sub->cnt[2]]);
    }
  else
    {
      calc = get_index(base, sub->nb2[sub->cnt[2]]);
      calc -= get_index(base, sub->nb1[sub->cnt[1]]);
    }
  if (calc < 0)
    {
      sub->res[sub->cnt[0]] = cvt_to_base(base, (calc + limit + *hold));
      *hold = -1;
    }
  else if (calc >= 0)
    {
      sub->res[sub->cnt[0]] = cvt_to_base(base, (calc + *hold));
      *hold = 0;
    }
}

int	init_sub(t_op *sub, char *nb1, char *nb2, char *base)
{
  if (nb_cmp(nb1, nb2, base) == 0)
    {
      sub->res = malloc(sizeof(char) * 2);
      sub->res[0] = '0';
      sub->res[1] = '\0';
      return (0);
    }
  else
    {
      sub->nb1 = nb1;
      sub->nb2 = nb2;
      sub->cnt[0] = (my_strlen(nb1) > my_strlen(nb2)) ?
	  my_strlen(nb1) : my_strlen(nb2);
      sub->res = malloc(sizeof(char) * (sub->cnt[0] + 2));
      sub->res[0] = '\0';
      sub->res[sub->cnt[0] + 1] = '\0';
      sub->cnt[1] = my_strlen(nb1) - 1;
      sub->cnt[2] = my_strlen(nb2) - 1;
    }
  return (1);
}

void	add_last_digits_sub(t_op *sub, char *base, int *hold)
{
  int		calc;
  ssize_t	limit;

  calc = 0;
  limit = my_strlen(base);
  if (sub->cnt[1] >= 0 && *hold == -1)
    {
      calc = get_index(base, sub->nb1[sub->cnt[1]]) + *hold;
      *hold = (calc < 0) ? -1 : 0;
      calc = (calc < 0) ? calc + limit : calc;
      sub->res[sub->cnt[0]] = cvt_to_base(base, calc);
    }
  else if (sub->cnt[1] >= 0 && *hold == 0)
    sub->res[sub->cnt[0]] = sub->nb1[sub->cnt[1]];
  else if (sub->cnt[2] >= 0 && *hold == -1)
    {
      calc = get_index(base, sub->nb2[sub->cnt[2]]) + *hold;
      *hold = (calc < 0) ? -1 : 0;
      calc = (calc < 0) ? calc + limit : calc;
      sub->res[sub->cnt[0]] = cvt_to_base(base, calc);
    }
  else if (sub->cnt[2] >= 0 && *hold == 0)
    sub->res[sub->cnt[0]] = sub->nb2[sub->cnt[2]];

}

void	ch_res_sub(t_op *sub, int is_neg, char *base)
{
  ssize_t	i;

  i = 0;
  if (is_neg && sub->res[1] != '0')
    sub->res[0] = '-';
  else
    sub->res = &(sub->res[1]);
  while (sub->res[i] != '\0' && sub->res[i] == base[0])
    {
      if (sub->res[i + 1] != base[0] && is_neg == 0)
	sub->res = &sub->res[i + 1];
      else if (sub->res[i + 1] != base[0] && is_neg == 1)
	{
	  sub->res[i] = '-';
	  sub->res = &sub->res[i];
	}
      i++;
    }
}
