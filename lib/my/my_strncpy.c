/*
** my_strcpy.c for my_strcpy in /home/thomas.couacault/CPool_Day06/
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.eu>
**
** Started on  Mon Oct 10 08:56:06 2016 John Doe
** Last update Tue Oct 11 15:21:08 2016 Thomas Couacault
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  if (n > i)
    dest[i] = '\0';
  return (dest);
}
