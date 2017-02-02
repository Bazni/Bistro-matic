/*
** my_str_isnum.c for my_str_isnum in /home/thomas.couacault/CPool_Day06
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Thu Oct  6 12:40:54 2016 Thomas Couacault
** Last update Tue Oct 11 15:20:20 2016 Thomas Couacault
*/

int	my_str_isnum(char *str)
{
  int	i;
  int	is_alpha;

  i = 0;
  if (str[0] != '\0')
    {
      while (str[i] != '\0')
	{
	  if (str[i] >= '0' && str[i] <= '9')
	    {
	      is_alpha = 1;
	    }
	  else
	    {
	      is_alpha = 0;
	    }
	  i++;
	}
      return (is_alpha);
    }
  else
    return (1);
}
