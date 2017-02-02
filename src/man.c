/*
** groupir.c for groupir in /home/gwendal.bazin/CPool_bistro-matic
**
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.net>
**
** Started on  Fri Nov 04 20:15:40 2016 Gwendal Bazin
** Last update Fri Nov 04 21:21:09 2016 Gwendal Bazin
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

void	man(char *av)
{
  if (my_strcmp("-h", av) == 0 || my_strcmp("--help", av) == 0)
    {
      my_putstr("USAGE\n");
      my_putstr("	   ./calc base operators size_read\n\n");
      my_putstr("DESCRIPTION\n");
      my_putstr("	   base	     all the symbols of the base\n");
      my_putstr("	   operators the symbols for the");
      my_putstr("parentheses and the 5 operators\n");
      my_putstr("	   size_read number of characters to be read\n");
    }
}
