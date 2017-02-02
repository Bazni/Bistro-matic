/*
** spaces.c for spaces in /home/maxime.gravier/CPool_bistro-maticMG/Errors
** 
** Made by maxime gravier
** Login   <maxime.gravier@epitech.net>
** 
** Started on  Sun Nov  6 23:19:47 2016 maxime gravier
** Last update Sun Nov  6 23:36:22 2016 maxime gravier
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "bistro-matic.h"
#include "my.h"

void	only_spaces(int i, char *expr, char **av)
{
  if (is_in_base(expr[0], av[1]) == 0 && is_in_base(expr[0], av[2]) == 0
      && expr[0] == ' ')
    {
      while (expr[++i] == ' ')
	{
	  if (expr[i + 1] == '\0')
	    exit(put_error(SYNTAX_ERROR_MSG, EXIT_SPACE));
	}
    }
}
