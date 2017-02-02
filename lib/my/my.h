/*
** my.h for my in /home/thomas.couacault/CPool_Day07/include
**
** Made by Thomas Couacault
** Login   <thomas.couacault@epitech.net>
**
** Started on  Tue Oct 11 18:39:18 2016 Thomas Couacault
** Last update Mon Oct 31 13:49:42 2016 maxime gravier
*/

#ifndef	MY_H_
# define MY_H_

void	my_putchar(char c);

int	my_isneg(int nb);

int	my_put_nbr(int nb);

int	my_swap(int *a, int *b);

int	my_putstr(char *str);

int	my_strlen(char *str);

int	my_atoi(char *str);

void	my_sort_int_tab(int *tab, int size);

int	my_power_rec(int nb, int power);

int	my_square_root(int nb);

int	my_is_prime(int nombre);

int	my_find_prime_sup(int nb);

char	*my_strcpy(char *dest, char *src);

char	*my_strncpy(char *dest, char *src, int n);

char	*my_revstr(char *str);

char	*my_strstr(char *str, char *to_find);

int	my_strcmp(char *s1, char *s2);

int	my_strncmp(char *s1, char *s2, int n);

char	*my_strupcase(char *str);

char	*my_strlowcase(char *str);

char	*my_strcapitalize(char *str);

int	my_str_isalpha(char *str);

int	my_str_isnum(char *str);

int	my_str_islower(char *str);

int	my_str_isupper(char *str);

int	my_str_isprintable(char *str);

int	my_showstr(char *str);

int	my_showmem(char *str, int size);

char	*my_strcat(char *dest, char *src);

char	*my_strncat(char *dest, char *src, int n);

int	my_show_wordtab(char **tab);

char	*my_strdup(char *str);

char	**my_str_to_wordtab(char *str);

int	calculate_nbr(char *str, int i, int end_while, int multiple);

void	display_limit();

void	display_nb(int nbr_d, int div, int nbr_c, int nb);

int	how_many_words(char *str);

int	is_alnum(char c);

int	is_prime(int nb);

int	my_power(int nb, int p);

int	my_strlen_again(char *str);

void	split_str(char **tab, char *str, int nb_words, int *lenght_words);

char	*strlowcase(char *str);

void	word_lenght(char *str, int nb_words, int *lenght_words);

#endif	/* !MY_H_ */
