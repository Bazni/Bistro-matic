/*
** my_strupcase.c for my_strupcase in /home/thomas.couacault/CPool_Day06
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Thu Oct  6 12:40:54 2016 Thomas Couacault
** Last update Tue Oct 11 15:18:21 2016 Thomas Couacault
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
      i++;
    }
  return (str);
}
