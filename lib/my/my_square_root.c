/*
** my_square_root.c for my_square_root in /home/thomas.couacault/CPool_Day05
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Fri Oct  7 15:04:05 2016 Thomas Couacault
** Last update Wed Oct 12 14:08:36 2016 Thomas Couacault
*/

int	my_power(int nb, int p)
{
  int	res;

  res = 1;
  if (p < 0)
    return (0);
  else if (p == 0)
    return (1);
  else
    {
      res = nb * my_power(nb, p - 1);
      if (res > 0)
	return (res);
      else
	return (0);
    }
}

int	my_square_root(int nb)
{
  int	square_root;
  int	sq_powered;

  square_root = 0;
  sq_powered = 0;
  if (nb < 0)
    return (0);
  else
    {
      while (sq_powered != nb)
	{
	  sq_powered = my_power(square_root, 2);
	  square_root++;
	}
      if (square_root != 0)
	{
	  square_root--;
	  return (square_root);
	}
      else
	return (0);
    }
}
