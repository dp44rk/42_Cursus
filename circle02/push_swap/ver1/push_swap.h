/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:07:54 by dpark             #+#    #+#             */
/*   Updated: 2022/08/31 18:08:08 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				origin;
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		numofdata;
}	t_stack;

typedef struct s_info
{
	int	cnt_ra;
	int	cnt_pb;
	int	cnt_rb;
	int	cnt_pa;
	int	pb;
	int	ps;
	int	low;
	int	high;
	int	len;
}	t_info;

/* stack */
void	insert_node_to_bottom(t_stack **a, int num, int data);
void	insert_node_to_top(t_stack **a, int num, int data);
void	restore_stack(t_stack *a, t_stack *b, int cnt, char *command);
int		pop_node(t_stack **stack);

/* parse */
void	parse_av(char **argv, t_stack *a);

/* operaction */
int		op(char *str, t_stack *gvn, t_stack *rcv);
// int		swap(t_stack *stack);
// int		push(t_stack *gvn, t_stack *rcv);
// int		rotate(t_stack **stack);
// int		r_rotate(t_stack **stack);

/* sort */
void	sort(t_stack *a, t_stack *b, t_info *info);
void	sort_4_to_5(t_stack *a, t_stack *b, int len);
void	sort_2_to_5_btoa(t_stack *a, t_stack *b, int len);
void	sort_2_to_5_atob(t_stack *a, t_stack *b, int len);

/* algo */
void	b_to_a(t_stack *a, t_stack *b, int len);
void	a_to_b(t_stack *a, t_stack *b, int len);
void	info_init(t_stack *s, t_info *info, int len);

/* libft */
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
bool	ft_strcmp(const char *s1, const char *s2);
void	ft_print_error(void);
void	*ft_alert_malloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);

#endif