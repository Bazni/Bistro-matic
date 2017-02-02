/*
** my_strcmp.c for my_strcmp in /home/thomas.couacault/CPool_Day04
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Thu Oct  6 12:40:54 2016 Thomas Couacault
** Last update Tue Oct 11 15:19:40 2016 Thomas Couacault
*/

int	my_strcmp(char *s1, char *s2)
{
  int	sum_s1;
  int	sum_s2;
  int	i;

  sum_s1 = 0;
  sum_s2 = 0;
  i = 0;
  while (s1[i] != '\0')
    {
      sum_s1 = sum_s1 + s1[i];
      i++;
    }
  i = 0;
  while (s2[i] != '\0')
    {
      sum_s2 = sum_s2 + s2[i];
      i++;
    }
  if (sum_s1 == sum_s2)
    return (0);
  else if (sum_s1 > sum_s2)
    return (1);
  else
    return (-1);
}
