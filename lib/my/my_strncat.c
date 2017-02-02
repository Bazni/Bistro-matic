/*
** my_strncat.c for my_strncat in /home/thomas.couacault/CPool_Day07
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Tue Oct 11 13:59:10 2016 Thomas Couacault
** Last update Tue Oct 11 17:49:46 2016 Thomas Couacault
*/

int	my_strlen(char *str);

char	*my_strncat(char *dest, char *src, int n)
{
  int	lenght_dest;
  int	lenght_src;
  int	i;

  lenght_dest = my_strlen(dest);
  lenght_src = my_strlen(src);
  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[lenght_dest + i] = src[i];
      i++;
    }
  dest[lenght_dest + lenght_src] = '\0';
  return (0);
}
