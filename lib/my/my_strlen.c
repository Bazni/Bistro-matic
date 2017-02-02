/*
** my_strlen.c for my_strlen in /home/thomas.couacault/CPool_Day04
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Thu Oct  6 10:53:08 2016 Thomas Couacault
** Last update Sat Nov 05 23:29:39 2016 Gwendal Bazin
*/

#include <stdio.h>

ssize_t		my_strlen(char *str)
{
  ssize_t	len;

  len = 0;
  while (str[len] != '\0')
    {
      len++;
    }
  return (len);
}
