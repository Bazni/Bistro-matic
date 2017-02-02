/*
** my_str_isalpha.c for my_str_isalpha in /home/thomas.couacault/CPool_Day06
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Thu Oct  6 12:40:54 2016 Thomas Couacault
** Last update Tue Oct 11 15:20:01 2016 Thomas Couacault
*/

int	my_str_isalpha(char *str)
{
  int	i;
  int	is_alpha;

  i = 0;
  if (str[0] != '\0')
    {
      while (str[i] != '\0')
	{
	  if (str[i] >= 'a' && str[i] <= 'z')
	    is_alpha = 1;
	  else if (str[i] >= 'A' && str[i] <= 'Z')
	    is_alpha = 1;
	  else
	    is_alpha = 0;
	  i++;
	}
      return (is_alpha);
    }
  else
    return (1);
}
