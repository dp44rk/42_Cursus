/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:17:55 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:17:57 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static bool	cmd_cmp(char *cmd, char *line)
{
	while (*cmd == *line)
	{
		if (*cmd == '\0')
			return (true);
		cmd++;
		line++;
	}
	return (false);
}

static int	convert_cmd(char *line)
{
	if (cmd_cmp("sa", line))
		return (SA);
	else if (cmd_cmp("sb", line))
		return (SB);
	else if (cmd_cmp("ss", line))
		return (SS);
	else if (cmd_cmp("pa", line))
		return (PA);
	else if (cmd_cmp("pb", line))
		return (PB);
	else if (cmd_cmp("ra", line))
		return (RA);
	else if (cmd_cmp("rb", line))
		return (RB);
	else if (cmd_cmp("rr", line))
		return (RR);
	else if (cmd_cmp("rra", line))
		return (RRA);
	else if (cmd_cmp("rrb", line))
		return (RRB);
	else if (cmd_cmp("rrr", line))
		return (RRR);
	return (ERROR);
}

static int	parse_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] != '\n')
		return (ERROR);
	line[len - 1] = '\0';
	return (convert_cmd(line));
}

static void	get_input(t_args *x)
{
	char	*line;
	int		cmd;

	while (true)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		cmd = parse_line(line);
		free(line);
		add_command_bonus(x, cmd);
	}
}

int	main(int ac, char **av)
{
	t_args	*x;

	if (ac == 1)
		exit_valid(NULL, NULL, STDERR_FILENO);
	if (!t_args_init(&x))
		exit_valid(NULL, "Error\n", STDERR_FILENO);
	if (!parse(x, ac, av))
		exit_valid(x, "Error\n", STDERR_FILENO);
	get_input(x);
	if (!do_command(x))
		exit_valid(x, "Error\n", STDERR_FILENO);
	if (is_aligned(x))
		exit_valid(x, "OK\n", STDOUT_FILENO);
	else
		exit_valid(x, "KO\n", STDOUT_FILENO);
}
