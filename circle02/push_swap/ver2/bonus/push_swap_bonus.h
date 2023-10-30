/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:18:39 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:18:41 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define BUFFER_SIZE 100

typedef struct s_stack {
	int	*s;
	int	now;
}				t_stack;

typedef struct s_group {
	int	len;
	int	done;
}				t_group;

typedef struct s_cmd {
	int				cmd;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_args {
	t_stack	*a;
	t_stack	*b;
	t_cmd	*cmds;
	int		cmds_len;
	int		number_len;
	int		*origin;
	bool	finish;
}				t_args;

typedef enum s_command {
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}			t_command;

typedef enum s_status {
	ERROR = -1,
	VALID,
}			t_status;

/* swap */
void	sa(t_args *x);
void	sb(t_args *x);
void	ss(t_args *x);

/* push */
void	pa(t_args *x);
void	pb(t_args *x);

/* rotate */
void	ra(t_args *x);
void	rb(t_args *x);
void	rr(t_args *x);

/* reverse_rotate */
void	rra(t_args *x);
void	rrb(t_args *x);
void	rrr(t_args *x);

/* libft_utils */
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
void	ft_putstr_fd(const char *s, int fd);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

/* t_args_init */
bool	t_args_init(t_args **x);

/* parse */
bool	parse(t_args *x, int ac, char **av);

/* parse2 */
bool	convert_numbers(int *origin, int *stack_a, int len);

/* libft_atoi */
char	*ft_atoi(char *str, int *dest);

/* free */
void	free_args(t_args *x);
void	j_free(void *p);

/* gnl */
char	*get_next_line(int fd);

/* gnl_utils */
char	*ft_strjoin_or_dup(char *save, char *buf);
char	*ft_strchr(const char *str, int c);
char	*ft_strchr(const char *str, int c);

/* exit */
void	exit_valid(t_args *x, char *s, int fd);
void	exit_invalid(t_args *x, char *s);

/* answer_print */
void	answer_print(t_args *x);

/* libft_lst */
t_cmd	*ft_lstnew(int cmd);
t_cmd	*ft_lstlast(t_cmd *head);
void	ft_lstclear(t_cmd **head);

/* checker_utils */
void	add_command_bonus(t_args *x, int cmd);
bool	do_command(t_args *x);
bool	is_aligned(t_args *x);

#endif
