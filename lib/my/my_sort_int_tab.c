/*
** my_sort_int_tab.c for my_sort_int_tab in /home/thomas.couacault/CPool_Day04
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Tue Oct 11 11:04:24 2016 Thomas Couacault
** Last update Wed Oct 12 14:07:24 2016 Thomas Couacault
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	y;
  int	tampon;

  while (i < size)
    {
      if (tab[size - 1] < tab[size - 2])
	{
	  i = 0;
	  y = size - 1;
	}
      if (tab[y] < tab[y - 1] && y > 0)
	{
	  tampon = tab[y];
	  tab[y] = tab[y - 1];
	  tab[y - 1] = tampon;
	}
      i++;
      y--;
    }
}
