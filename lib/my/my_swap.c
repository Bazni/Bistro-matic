/*
** my_swap.c for my_swap in /home/thomas.couacault/CPool_Day04
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Thu Oct  6 08:56:28 2016 Thomas Couacault
** Last update Wed Oct 12 10:11:52 2016 Thomas Couacault
*/

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
