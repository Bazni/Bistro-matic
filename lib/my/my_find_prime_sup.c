/*
** my_find_prime_sup.c for my_find_prime_sup in /home/thomas.couacault/CPool_Day05
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Fri Oct  7 16:09:03 2016 Thomas Couacault
** Last update Wed Oct 12 10:12:38 2016 Thomas Couacault
*/

int	is_prime(int nb)
{
  int	divider;

  divider = 1;
  if (nb >= 2)
    {
      while (divider <= nb)
	{
	  if (nb % divider == 0)
	    {
	      if (divider > 1 && divider < nb)
		return (0);
	      else if (divider == nb)
		return (1);
	    }
	  else
	    return (1);
	  divider++;
	}
    }
  else
    return (0);
}

int	my_find_prime_sup(int nb)
{
  int	state;

  state = is_prime(nb);
  if (state == 0 && nb > 2)
    {
      while (state == 0)
	{
	  nb++;
	  state = is_prime(nb);
	  return (nb);
	}
    }
  else
    return (nb);
}
