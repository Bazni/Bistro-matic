/*
** my_strcapitalize.c for my_strcapitalize in /home/thomas.couacault/CPool_Day06
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Thu Oct  6 12:40:54 2016 Thomas Couacault
** Last update Wed Oct 12 10:06:13 2016 Thomas Couacault
*/

char	*strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	{
	  str[i] = str[i] + 32;
	}
      i++;
    }
  return (str);
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  str = strlowcase(str);
  if (str[0] >= 'a' && str[0] <= 'z')
    str[0] = str[0] - 32;
  while (str[i] != '\0')
    {
      if (str[i + 1] != '\0')
	{
	  if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
	    {
	      if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
		str[i + 1] = str[i + 1] - 32;
	    }
	}
      i++;
    }
  return (str);
}
