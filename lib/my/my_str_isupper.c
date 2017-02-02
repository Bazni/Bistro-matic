/*
** my_str_isupper.c for my_str_isupper in /home/thomas.couacault/CPool_Day06
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Thu Oct  6 12:40:54 2016 Thomas Couacault
** Last update Tue Oct 11 15:20:40 2016 Thomas Couacault
*/

int	my_str_isupper(char *str)
{
  int	i;
  int	is_upper;

  i = 0;
  if (str[0] != '\0')
    {
      while (str[i] != '\0')
	{
	  if (str[i] >= 'A' && str[i] <= 'Z')
	    {
	      is_upper = 1;
	    }
	  else
	    {
	      is_upper = 0;
	    }
	  i++;
	}
      return (is_upper);
    }
  else
    return (1);
}
