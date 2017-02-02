/*
** sub_inf.c for bistro-matic in /home/thomas.couacault/rendu/CPool_bistro-matic
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Tue Nov  1 16:57:39 2016 Thomas Couacault
** Last update Sun Nov 06 23:25:00 2016 Gwendal Bazin
*/

#include "my.h"
#include "bistro-matic.h"
#include <stdio.h>
#include <stdlib.h>

void	decrement(ssize_t *cnt)
{
  cnt[0]--;
  cnt[1]--;
  cnt[2]--;
}

char	*sub_inf(char *nb1, char *nb2, char *base)
{
  int	res_is_neg, hold;
  t_op	sub;

  if (init_sub(&sub, nb1, nb2, base) == 0)
    return (sub.res);
  res_is_neg = (nb_cmp(nb2, nb1, base) > 0) ? 1 : 0;
  hold = 0;
  while (sub.cnt[1] >= 0 || sub.cnt[2] >= 0)
    {
      if (sub.cnt[1] >= 0 && sub.cnt[2] >= 0)
	compute_sub(&sub, base, &hold);
      else
	add_last_digits_sub(&sub, base, &hold);
      decrement(sub.cnt);
    }
  ch_res_sub(&sub, res_is_neg, base);
  return (sub.res);
}
