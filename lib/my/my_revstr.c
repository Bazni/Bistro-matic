/*
** my_revstr.c for my_revstr in /home/thomas.couacault/CPool_Day04
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Thu Oct  6 12:40:54 2016 Thomas Couacault
** Last update Sat Nov 05 11:04:23 2016 Gwendal Bazin
*/

#include "my.h"
#include <stdlib.h>

char	*my_revstr(char *str)
{
  char		tampon;
  size_t	len;
  size_t	i;

  i = 0;
  tampon = '\0';
  len = my_strlen(str);
  if (len <= 1)
    return (str);
  len = my_strlen(str) - 1;
  while (i <= (len / 2))
    {
      tampon = str[i];
      str[i] = str[len - i];
      str[len - i] = tampon;
      i++;
    }
  return (str);
}
