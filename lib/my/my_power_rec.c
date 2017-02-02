/*
** my_power_rec.c for my_power_rec in /home/thomas.couacault/CPool_Day05
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Fri Oct  7 11:22:45 2016 Thomas Couacault
** Last update Wed Oct 12 10:14:17 2016 Thomas Couacault
*/

int	my_power_rec(int nb, int p)
{
  int	res;

  res = 1;
  if (p < 0 || nb < 0)
    return (0);
  else if (p == 0)
    return (1);
  else
    {
      res = nb * my_power_rec(nb, p - 1);
      if (res > 0)
	return (res);
      else
	return (0);
    }
}
