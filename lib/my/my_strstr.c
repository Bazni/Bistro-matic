/*
** my_strstr.c for my_strstr in /home/thomas.couacault/CPool_Day04
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Thu Oct  6 12:40:54 2016 Thomas Couacault
** Last update Tue Oct 11 20:21:13 2016 Thomas Couacault
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	y;
  int	begin;

  i = 0;
  y = 0;
  while (str[i] != '\0')
    {
      if (str[i] == to_find[y])
	{
	  begin = i;
	  while (str[i] != '\0' && to_find[y] != '\0' && str[i] == to_find[y])
	    {
	      i++;
	      y++;
	    }
	  if (to_find[y] == '\0')
	    return (&str[begin]);
	  y = 0;
	  i = begin;
	}
      i++;
    }
  return (0);
}
