/*
** mult_inf.c for mult_inf in /home/gwendal.bazin/CPool_bistro-matic
**
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.net>
**
** Started on  Wed Nov 02 18:43:11 2016 Gwendal Bazin
** Last update Sun Nov 06 23:21:53 2016 Gwendal Bazin
*/
#include "my.h"
#include "bistro-matic.h"
#include <stdio.h>
#include <stdlib.h>

void	*my_memset(char *s, char c, size_t nb)
{
  size_t	i;

  i = 0;
  while (i <= nb)
    {
      s[i] = c;
      i++;
    }
  s[i] = '\0';
  return (s);
}

int	init_mult(t_op *mult, char *nb1, char *nb2, char *base)
{
  if (nb1[0] == base[0] || nb2[0] == base[0])
    {
      if ((mult->res = malloc(sizeof(char) *  2)) == NULL)
	exit(put_error(ERROR_MSG, EXIT_MALLOC));
      mult->res[1] = '\0';
      mult->res[0] = base[0];
      return (0);
    }
  else
    {
      mult->nb1 = nb1;
      mult->nb2 = nb2;
      mult->cnt[1] = my_strlen(nb1);
      mult->cnt[2] = my_strlen(nb2);
      mult->cnt[0] = mult->cnt[1] + mult->cnt[2];
      if ((mult->res = malloc(sizeof(char) * (mult->cnt[0] + 4))) == NULL)
	exit(put_error(ERROR_MSG, EXIT_MALLOC));
      my_memset(mult->res, cvt_to_base(base, 0), mult->cnt[0]);
    }
  return (1);
}

void	neg_nbr(t_op *mult, int *res_is_neg)
{
  if (mult->nb1[0] == '-')
    {
      mult->nb1 = &mult->nb1[1];
      mult->cnt[1]--;
      *res_is_neg = 1;
    }
  else if (mult->nb2[0] == '-')
    {
      mult->nb2 = &mult->nb2[1];
      mult->cnt[2]--;
      *res_is_neg = 1;
    }
}

void	calc_digit(char *base, t_op *mult, int calc, int hold)
{
  calc = get_index(base, mult->nb2[mult->cnt[2] - 1])
      * get_index(base, mult->nb1[mult->cnt[1] - 1]);
  hold = get_index(base, mult->res[mult->cnt[1] + mult->cnt[2]])
      + (calc % my_strlen(base));
  mult->res[mult->cnt[1] + mult->cnt[2]] = cvt_to_base(base,
						    hold % my_strlen(base));
  mult->res[mult->cnt[1] + mult->cnt[2] - 1] = cvt_to_base(base,
		get_index(base, mult->res[mult->cnt[1] + mult->cnt[2] - 1])
			+ (hold / my_strlen(base)) + (calc / my_strlen(base)));
  mult->cnt[1]--;
}
char	*mult_inf(char *nb1, char *nb2, char *base)
{
  int	res_is_neg, carry, hold, calc;
  t_op	mult;

  res_is_neg = carry = hold = calc = 0;
  if (init_mult(&mult, nb1, nb2, base) == 0)
    return (mult.res);
  neg_nbr(&mult, &res_is_neg);
  while (mult.cnt[2] > 0)
    {
      while (mult.cnt[1] > 0)
	calc_digit(base, &mult, calc, hold);
      mult.cnt[2]--;
      mult.cnt[1] = my_strlen(mult.nb1);
    }
  if (res_is_neg)
    mult.res[0] = '-';
  while (mult.res[carry] == cvt_to_base(base, 0))
    carry++;
  return (&mult.res[carry]);
}
