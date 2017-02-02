/*
** my_str_isupper.c for my_str_isupper in /home/thomas.couacault/CPool_Day06
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Thu Oct  6 12:40:54 2016 Thomas Couacault
** Last update Tue Oct 11 15:20:29 2016 Thomas Couacault
*/

int	my_str_isprintable(char *str)
{
  int	i;
  int	is_printable;

  i = 0;
  if (str[0] != '\0')
    {
      while (str[i] != '\0')
	{
	  if (str[i] > 31)
	    {
	      is_printable = 1;
	    }
	  else
	    {
	      is_printable = 0;
	    }
	  i++;
	}
      return (is_printable);
    }
  else
    return (1);
}
