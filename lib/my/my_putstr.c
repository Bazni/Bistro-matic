/*
** my_putstr.c for my_putstr in /home/thomas.couacault/CPool_Day04
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Thu Oct  6 09:39:13 2016 Thomas Couacault
** Last update Wed Oct 12 14:05:08 2016 Thomas Couacault
*/

void	my_putchar(char c);

int	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
  return (0);
}
