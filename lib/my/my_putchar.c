/*
** my_put_char.c for my_put_char in /home/thomas.couacault/CPool_Day03
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Wed Oct  5 10:27:47 2016 Thomas Couacault
** Last update Wed Oct 12 14:02:28 2016 Thomas Couacault
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
