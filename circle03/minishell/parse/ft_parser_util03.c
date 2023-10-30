/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_util03.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:37:53 by sangminpark       #+#    #+#             */
/*   Updated: 2023/01/14 01:22:37 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_itoa_len(long long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	file_name_size(char *str)
{
	int	cnt;
	int	space;

	cnt = 0;
	space = 1;
	cnt++;
	if ((str[0] == '<' && str[1] == '<') || (str[0] == '>' && str[1] == '>'))
		cnt++;
	while (is_space(str[cnt]) == 1)
		cnt++;
	while (str[cnt] && space == 1 && str[cnt] != '>' && str[cnt] != '<')
	{
		if (is_space(str[cnt]) == 1)
			space = 0;
		cnt++;
	}
	cnt--;
	return (cnt);
}

t_token	*is_redirects_func(t_token *tree, char *str)
{
	char	*chr;
	int		space;

	space = 1;
	chr = 0;
	chr = fts_strjoin(chr, str[0], 0);
	if ((str[0] == '<' && str[1] == '<') || (str[0] == '>' && str[1] == '>'))
	{
		chr = fts_strjoin(chr, str[1], 0);
		str++;
	}
	str++;
	while (is_space(str[0]) == 1)
		str++;
	chr = fts_strjoin(chr, ' ', 0);
	while (*str && space == 1 && str && *str != '>' && *str != '<')
	{
		if (is_space(str[0]) == 1)
			space = 0;
		else
			chr = fts_strjoin(chr, str[0], 0);
		str++;
	}
	tree = insert_red_node(tree, chr, T_REDS);
	return (tree);
}

int	quotes_size(char line)
{
	if (line == '\"' || line == '\'')
		return (1);
	return (0);
}

int	env_size_len(t_scmd *cmd, char *line)
{
	if (*line == '$' && cmd->quotes != 1 && quotes_size(line[1]) != 1 && \
			line[1] != ' ' && line[1] && line[1] != '$')
		return (1);
	return (0);
}
