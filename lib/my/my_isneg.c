/*
** my_isneg.c for my_isneg in /home/thomas.couacault/CPool_Day03
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Wed Oct  5 12:15:06 2016 Thomas Couacault
** Last update Wed Oct 12 10:13:23 2016 Thomas Couacault
*/

void	my_putchar(char c);

int	my_isneg(int n)
{
  if (n < 0)
    {
      my_putchar('N');
    }
  else
    {
      my_putchar('P');
    }
  return (0);
}
