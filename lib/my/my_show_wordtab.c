/*
** my_show_wordtab.c for my_show_wordtab in /home/thomas.couacault/CPool_Day08/task03
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Wed Oct 12 14:14:18 2016 Thomas Couacault
** Last update Wed Oct 12 15:19:59 2016 Thomas Couacault
*/

void	my_putchar(char c);

int	my_show_wordtab(char **tab)
{
  int	i;
  int	y;

  i = 0;
  y = 0;
  while (tab[i] != 0)
    {
      while (tab[i][y] != '\0')
	{
	  my_putchar(tab[i][y]);
	  y++;
	}
      my_putchar('\n');
      y = 0;
      i++;
    }
  return (0);
}
