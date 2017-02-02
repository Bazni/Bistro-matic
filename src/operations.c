/*
** operations.c for bistro-matic in /home/thomas.couacault/rendu/CPool_bistro-matic
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Wed Nov  2 08:58:14 2016 Thomas Couacault
** Last update Sun Nov 06 23:24:36 2016 Gwendal Bazin
*/

#include "my.h"
#include "bistro-matic.h"
#include <stdio.h>
#include <stdlib.h>

int	is_in_base(char c, char *base)
{
  ssize_t	i;

  i = 0;
  while (base[i] != '\0')
    {
      if (c == base[i])
	return (1);
      i++;
    }
  return (0);
}

int	 is_in_ops(char c, char *ops)
{
  ssize_t	 i;

  i = 2;
  while (ops[i] != '\0')
    {
      if (c == ops[i])
	return (1);
      i++;
    }
  return (0);
}

ssize_t		get_index(char *base, char c)
{
  ssize_t	k;

  k = 0;
  while (base[k] != '\0')
    {
      if (c == base[k])
	return (k);
      k++;
    }
  exit(put_error(ERROR_MSG, EXIT_BASE));
}

char	cvt_to_base(char *base, int calc)
{
  return (base[calc]);
}

int	nb_cmp(char *nb1, char *nb2, char *base)
{
  ssize_t	i;

  i = 0;
  if (my_strlen(nb1) > my_strlen(nb2))
    return (1);
  else if (my_strlen(nb1) < my_strlen(nb2))
    return (-1);
  else if (my_strlen(nb1) == my_strlen(nb2))
    {
      while (nb1[i] != '\0')
        {
          if (get_index(base, nb1[i]) > get_index(base, nb2[i]))
            return (1);
          else if (get_index(base, nb1[i]) < get_index(base, nb2[i]))
            return (-1);
          i++;
        }
    }
  return (0);
}
