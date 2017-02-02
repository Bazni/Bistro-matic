/*
** my_strcmp.c for my_strcmp in /home/thomas.couacault/CPool_Day06
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Thu Oct  6 12:40:54 2016 Thomas Couacault
** Last update Tue Oct 11 15:20:59 2016 Thomas Couacault
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
    {
      i++;
    }
  if ((s1[i] - s2[i]) > 0)
    {
      return (1);
    }
  else if ((s1[i] - s2[i]) < 0)
    {
      return (-1);
    }
  else
    {
      return (0);
    }
}
