/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:39:49 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/21 18:39:42 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 16

typedef struct s_elem
{
	int				val;
	int				index;
	struct s_elem	*next;
	struct s_elem	*prev;
}	t_elem;

typedef struct s_stack
{
	t_elem	*top;
	t_elem	*root;
	int		size;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		nmoves;
}	t_data;

typedef struct s_checker
{
	int		gnl_ret;
	char	*line;
}	t_checker;

void	init_data(t_data *data);
void	init_structures(t_data *data, t_stack *a_stack, t_stack *b_stack);
int		no_doubles(t_stack *stack);
int		errors(int i);

t_elem	*create_elem(int value);
t_elem	*add_elem(t_elem *prev_el, int value);
t_elem	*del_elem(t_elem *elem);

int		ft_atoi(const char *s);
int		ft_isdigit(int c);
int		all_ints(char **line, int arg_num);

void	init_stack(t_stack *stack);
void	fill_stack(char **args, int size, t_stack *stack);
int		stack_sorted(t_stack *stack);
void	clear_stack(t_stack *stack);

void	stack_push(t_stack *stack, t_elem *elem);
t_elem	*stack_pop(t_stack *stack);
void	stack_topswap(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	r_rotate_stack(t_stack *stack);

void	sa(t_stack *a, int *moves);
void	sb(t_stack *b, int *moves);
void	pa(t_stack *a, t_stack *b, int *moves);
void	pb(t_stack *a, t_stack *b, int *moves);
void	ra(t_stack *stack_a, int *moves);
void	rb(t_stack *stack_b, int *moves);
void	rra(t_stack *stack_a, int *moves);
void	rrb(t_stack *stack_b, int *moves);
void	ss(t_stack *stack_a, t_stack *stack_b, int *moves);
void	rr(t_stack *stack_a, t_stack *stack_b, int *moves);
void	rrr(t_stack *stack_a, t_stack *stack_b, int *moves);

int		index_stack(t_stack *stack);
void	pa2nums(t_data *data, int radix, int num1, int num2);
int		radix_digit(int num, int radix);
void	pa3numsinorder(t_data *data, int radix, int maxnum);
int		nums_in_stack(t_stack *stack, int radix, char *numstr, int num);

void	short_pb3_pbrb1(t_data *data, int radix, char *upstr, int downnum);
void	short_sort_2last(t_data *data, int radix, int lessnum);

int		get_max_radix(int num);
int		digit_in_str(int digit, char *strnum);

void	paall(t_data *data);
void	rrbpa(t_data *data, int num, int radix);

void	sort_stack(t_data *data);
void	sort_small_stack(t_data *data);
void	sort_no_order(t_data *data, int radix);

void	print_stack_full(t_stack *stack);
void	print_stack(t_stack *stack);
void	print_stack_indx(t_stack *stack);

int		nums_in_stack(t_stack *stack, int radix, char *numstr, int num);
int		numstrs_in_stack(t_stack *stack, int radix,
			char *numstr1, char *numstr2);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		strchr_index(char *s, int c);
int		get_next_line(int fd, char **line);

void	checker_push(t_stack *stack_a, t_stack *stack_b);
void	checker_rotate(t_stack *stack_a, t_stack *stack_b, int mode);
void	checker_swap(t_stack *a, t_stack *b);
int		checker_sorted(t_stack *a_stack, t_stack *b_stack);

#endif
