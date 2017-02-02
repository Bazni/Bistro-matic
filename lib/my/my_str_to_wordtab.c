/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/thomas.couacault/CPool_Day08/task04
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Wed Oct 12 15:38:48 2016 Thomas Couacault
** Last update Sat Oct 29 21:09:16 2016 Thomas Couacault
*/

#include <stdlib.h>

int	my_strlen(char *str);

int	my_putstr(char *str);

void	my_putchar(char c);

int	is_alnum(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  else if (c >= 'A' && c <= 'Z')
    return (1);
  else if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

int	how_many_words(char *str)
{
  int	nb_words;
  int	i;

  nb_words = 0;
  i = 0;
  while (str[i] != '\0' && str[0] != '\0')
    {
      if (!is_alnum(str[i]) && is_alnum(str[i + 1])
	  && i < (my_strlen(str) - 1))
	{
	  nb_words++;
	}
      i++;
    }
  return (nb_words + 1);
}

void	word_lenght(char *str, int nb_words, int *lenght_words)
{
  int	i;
  int	y;

  i = 0;
  y = 0;
  while (y < nb_words)
    {
      lenght_words[y] = 0;
      y++;
    }
  y = 0;
  while (str[i] != '\0' && y < nb_words)
    {
      if (is_alnum(str[i]) && is_alnum(str[i + 1]))
	lenght_words[y]++;
      else if (!is_alnum(str[i]) && is_alnum(str[i + 1]))
	{
	  lenght_words[y] = lenght_words[y] + 2;
	  y++;
	}
      i++;
    }
}

void	split_str(char **tab, char *str, int nb_words, int *lenght_words)
{
  int	i;
  int	y;
  int	z;

  i = y = z = 0;
  while (str[i] != '\0' && y < nb_words - 1)
    {
      if (is_alnum(str[i]) && z <= lenght_words[y])
	{
	  tab[y][z] = str[i];
	  my_putstr(tab[y]);
	  my_putchar('\n');
	  my_putchar(lenght_words[y] + 48);
	  z++;
	}
      else if (z == lenght_words[y] && is_alnum(str[i + 1]))
	{
	  tab[y][z + 1] = '\0';
	  z = 0;
	  y++;
	}
      i++;
    }
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	nb_words;
  int	*lenght_words;
  int	i;

  nb_words = how_many_words(str) + 1;
  lenght_words = malloc(sizeof(int) * (nb_words - 1));
  if ((tab = malloc(sizeof(char *) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  word_lenght(str, nb_words - 1, lenght_words);
  i = 0;
  while (i < nb_words - 1)
    {
      tab[i] = malloc(sizeof(char) * (lenght_words[i] + 1));
      i++;
    }
  split_str(tab, str, nb_words, lenght_words);
  return (tab);
}
