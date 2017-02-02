/*
** my_is_prime.c for my_is_prime in /home/thomas.couacault/CPool_Day05
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Fri Oct  7 16:09:03 2016 Thomas Couacault
** Last update Wed Oct 12 10:13:48 2016 Thomas Couacault
*/

int	my_is_prime(int nb)
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
