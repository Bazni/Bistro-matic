/*
** sub_inf.c for bistro-matic in /home/thomas.couacault/rendu/CPool_bistro-matic
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Tue Nov  1 16:57:39 2016 Thomas Couacault
** Last update Sat Nov  5 13:47:36 2016 maxime gravier
*/

#include "my.h"
#include "bistro-matic.h"
#include <stdio.h>
#include <stdlib.h>

void	decrement_add(ssize_t *cnt)
{
  cnt[0]--;
  cnt[1]--;
  cnt[2]--;
}

char	*add_inf(char *nb1, char *nb2, char *base)
{
  int	hold;
  t_op	add;

  init_add(&add, nb1, nb2);
  hold = 0;
  while (add.cnt[1] >= 0 || add.cnt[2] >= 0)
    {
      if (add.cnt[1] >= 0 && add.cnt[2] >= 0)
	compute_add(&add, base, &hold);
      else
	add_last_digits_add(&add, base, &hold);
      decrement_add(add.cnt);
    }
  if (hold == 1)
    {
      add.res[0] = base[1];
      return (add.res);
    }
  else
    return (&(add.res[1]));
}
