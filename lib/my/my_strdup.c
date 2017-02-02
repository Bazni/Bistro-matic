/*
** my_strdup.c for my_strdup in /home/thomas.couacault/CPool_Day08/task01
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Wed Oct 12 10:22:59 2016 Thomas Couacault
** Last update Thu Oct 13 09:59:09 2016 Thomas Couacault
*/

#include <stdlib.h>

int	my_strlen(char *str);

char	*my_strdup(char *str)
{
  char	*my_string;
  int	i;

  i = 0;
  my_string = malloc(sizeof(char) * (my_strlen(str)));
  while (i < my_strlen(str))
    {
      my_string[i] = str[i];
      i++;
    }
  return (my_string);
}
