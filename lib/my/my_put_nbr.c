/*
** my_put_nbr.c for my_put_nbr in /home/thomas.couacault/CPool_Day03
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Wed Oct  5 19:14:32 2016 Thomas Couacault
** Last update Sun Oct 30 06:09:31 2016 Thomas Couacault
*/

void	my_putchar(char c);

void	disp_positive(int nb)
{
  if (nb / 10)
    disp_positive(nb / 10);
  my_putchar(nb % 10 + '0');
}

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  disp_positive(nb);
  return (0);
}
