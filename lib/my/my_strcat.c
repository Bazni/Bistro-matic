/*
** my_strcat.c for my_strcat in /home/thomas.couacault/CPool_Day07
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Tue Oct 11 13:59:10 2016 Thomas Couacault
** Last update Tue Oct 11 17:39:12 2016 Thomas Couacault
*/

int	my_strlen(char *str);

char	*my_strcat(char *dest, char *src)
{
  int	lenght_dest;
  int	lenght_src;
  int	i;

  lenght_dest = my_strlen(dest);
  lenght_src = my_strlen(src);
  i = 0;
  while (i < lenght_dest && src[i] != '\0')
    {
      dest[lenght_dest + i] = src[i];
      i++;
    }
  dest[lenght_dest + lenght_src] = '\0';
  return (0);
}
