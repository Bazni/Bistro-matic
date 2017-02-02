/*
** my_strcpy.c for my_strcpy in /home/thomas.couacault/CPool_Day06/
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.eu>
**
** Started on  Mon Oct 10 08:56:06 2016 John Doe
** Last update Wed Oct 12 10:07:11 2016 Thomas Couacault
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
