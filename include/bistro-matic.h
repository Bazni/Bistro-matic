/*
** bistro-matic.h for bistro-matic in /home/maxime.gravier/CPool_bistro-matic
**
** Made by maxime gravier
** Login   <maxime.gravier@epitech.net>
**
** Started on  Mon Oct 31 11:57:21 2016 maxime gravier
** Last update Sun Nov  6 23:27:06 2016 maxime gravier
*/
#ifndef	BISTRO_MATIC_H_
# define BISTRO_MATIC_H_

#define OPEN_PARENT	0
#define CLOSE_PARENT	1
#define PLUS		2
#define SUB		3
#define	MULT		4
#define DIV		5
#define MOD		6

#define EXIT_USAGE	84
#define EXIT_BASE	84
#define EXIT_SIZE_NEG	84
#define EXIT_MALLOC	84
#define EXIT_READ	84
#define EXIT_NUMBER	84
#define EXIT_OPS	84
#define	EXIT_PARENT	84
#define EXIT_SPACE	84

#define SYNTAX_ERROR_MSG	"syntax error"
#define ERROR_MSG		"error"

#include <stdio.h>

typedef	struct		s_npi_l
{
  char			*nb;
  char			op;
  struct s_npi_l	*next;
  struct s_npi_l	*prev;
}			t_npi_l;

typedef struct	s_stack
{
  char			op;
  struct s_stack	*next;
}		t_stack;

typedef	struct	s_op
{
  char		*res;
  char		*nb1;
  char		*nb2;
  ssize_t	cnt[3];
}		t_op;

typedef	struct	s_npi
{
  char		*expr;
  char		**npi;
  ssize_t	len;
  ssize_t	cnt[2];
}		t_npi;

typedef struct		s_nbr
{
  struct s_npi_l	*op;
  struct s_npi_l        *nb1;
  struct s_npi_l        *nb2;
  struct s_npi_l        *begin;
  char			*base;
  char			*res;
  ssize_t		len_npi;
}			t_nbr;

void	add_op_npi(t_stack **, t_npi *);

ssize_t	cnt_nodes(t_nbr *, char *);

t_npi_l	*get_op(t_npi_l **, char *);

void	get_nb(t_nbr *);

void	get_nb(t_nbr *);

t_npi_l	*get_op(t_npi_l **, char *);

ssize_t	get_len_npi(char *, char *, char *);

void	match_ope(t_nbr *, char *);

void	del_node(t_npi_l **);

void	init_calc(t_nbr *, char **, t_npi_l **);

ssize_t	get_len_list(t_npi_l **);

void	display_npi_l(t_npi_l **);

void	add_node(t_npi_l **, char *, t_nbr *, char *);

char	*eval_expr(char *, char *, char **, unsigned int);

void	cmpt(char *, int *, char *, int);

int	put_error(char *, int);

int	nb_chars(char *, char *, char *);

int	nb_strings(char *, char *, char *);

ssize_t	get_index(char *, char);

char	cvt_to_base(char *, int);

int	is_in_base(char, char *);

int	is_in_ops(char, char *);

ssize_t	malloc_npi(char *, char **, char *, char *);

void	empty_npi_l(t_nbr *, char *);

int	prio_op(char);

int	is_in_base(char, char *);

int	is_op(char);

int	nb_columns(char *);

int	nb_rows(char *);

void	add_paren_in_stack(t_stack **, char);

void	add_op_in_stack(t_stack **, char, char *);

void	suppr_stack(t_stack **);

void	empty_stack(t_stack **, t_npi *);

void	add_nb_npi(t_npi *, char *);

void	add_op_npi(t_stack **, t_npi *);

void	handle_paren_cl(t_stack **, t_npi *, char *);

void	handle_op(t_stack **, t_npi *, char *);

ssize_t	npi_transform(char *, char **, char *, char *);

void	ch_res_sub(t_op *, int, char *);

void	add_last_digits_sub(t_op *, char *, int *);

int	init_sub(t_op *, char *, char *, char *);

void	compute_sub(t_op *, char *, int *);

int	nb_cmp(char *, char *, char *);

void	compute_add(t_op *, char *, int *);

void	init_add(t_op *, char *, char *);

void	add_last_digits_add(t_op *, char *, int *);

void	d_char_in_base(char **);

void	char_in_both_base(char *, char *);

void	ope_first(int, int, char *, char **);

void	check_space(int, char *, char **);

void	check_number(int, char *, char **);

int	check_open(int, int, char *, char **);

int	check_close(int, int, char *, char **);

int	check_operator(int, int, char *, char **);

void	only_spaces(int, char *, char **);

void	expr_errors(char *, char **);

int	get_nbr_npi(int, char*, char*);

void	get_both_nbrs(char *, t_nbr *, int, int);

void	match_op(t_nbr *, char, char *, char *);

char	*get_result(int, t_nbr *, char *, char *);

char	*calculate(char *, char **);

char	*add_inf(char *, char *, char *);

char    *div_inf(char *, char *, char *);

char    *mod_inf(char *, char *, char *);

char	*sub_inf(char *, char *, char *);

char	*mult_inf(char *, char *, char *);

void	man(char *);

#endif	/* !BISTRO_MATIC_H_ */
