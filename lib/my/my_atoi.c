/*
** my_getnbr.c for my_getnbr in /home/maxime.gravier/CPool_Day04
** 
** Made by maxime gravier
** Login   <maxime.gravier@epitech.net>
** 
** Started on  Tue Oct 11 08:47:07 2016 maxime gravier
** Last update Mon Oct 31 13:48:52 2016 maxime gravier
*/

int	my_atoi(char *str)
{
  int	i;
  int	j;
  int	k;
  
  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  k = i;
	  while (str[i] >= '0' && str[i] <= '9')
	    {
	      j = ((j * 10) + (str[i] - 48));
	      i++;
	    }
	  if (str[k - 1] == '-')
	    j *= -1;
	  return (j);
	}
      else
	i++;
    }
  return (0);
}
