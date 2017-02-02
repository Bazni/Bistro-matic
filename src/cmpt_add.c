/*
** sub_inf.c for bistro-matic in /home/thomas.couacault/rendu/CPool_bistro-matic
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Tue Nov  1 16:57:39 2016 Thomas Couacault
** Last update Sun Nov  6 17:56:27 2016 maxime gravier
*/

#include "my.h"
#include "bistro-matic.h"
#include <stdio.h>
#include <stdlib.h>

void	compute_add(t_op *add, char *base, int *hold)
{
  int		calc;
  ssize_t	limit;

  limit = my_strlen(base);
  calc = get_index(base, add->nb1[add->cnt[1]]) + *hold;
  calc += get_index(base, add->nb2[add->cnt[2]]);
  if (calc >= limit)
    {
      add->res[add->cnt[0]] = cvt_to_base(base, (calc - limit));
      *hold = 1;
    }
  else if (calc < limit)
    {
      add->res[add->cnt[0]] = cvt_to_base(base, calc);
      *hold = 0;
    }
}

void	init_add(t_op *add, char *nb1, char *nb2)
{
  ssize_t	max_len;

  if (my_strlen(nb1) > my_strlen(nb2))
    max_len = my_strlen(nb1);
  else
    max_len = my_strlen(nb2);
  add->nb1 = nb1;
  add->nb2 = nb2;
  if ((add->res = malloc(sizeof(char) * (max_len + 2))) == NULL)
    exit(put_error(ERROR_MSG, EXIT_MALLOC));
  add->res[max_len + 1] = '\0';
  add->res[0] = '\0';
  add->cnt[0] = max_len;
  add->cnt[1] = my_strlen(nb1) - 1;
  add->cnt[2] = my_strlen(nb2) - 1;
}

void	add_last_digits_add(t_op *add, char *base, int *hold)
{
  int		calc;
  ssize_t	limit;

  limit = my_strlen(base);
  calc = 0;
  if (add->cnt[1] >= 0 && *hold == 1)
    {
      calc = get_index(base, add->nb1[add->cnt[1]]) + *hold;
      *hold = (calc >= limit) ? 1 : 0;
      calc = (calc >= limit) ? calc - limit : calc;
      add->res[add->cnt[0]] = cvt_to_base(base, calc);
    }
  else if (add->cnt[1] >= 0 && *hold == 0)
    add->res[add->cnt[0]] = add->nb1[add->cnt[1]];
  else if (add->cnt[2] >= 0 && *hold == 1)
    {
      calc = get_index(base, add->nb2[add->cnt[2]]) + *hold;
      *hold = (calc >= limit) ? 1 : 0;
      calc = (calc >= limit) ? calc - limit : calc;
      add->res[add->cnt[0]] = cvt_to_base(base, calc);
    }
  else if (add->cnt[2] >= 0 && *hold == 0)
    add->res[add->cnt[0]] = add->nb2[add->cnt[2]];
}
