/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:32:52 by sangminpark       #+#    #+#             */
/*   Updated: 2023/01/15 23:43:45 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_free_token(t_token *token)
{
	if (token == 0)
		return ;
	ft_free_token(token->left);
	ft_free_token(token->right);
	free(token);
}

int	quotes_func_len(int quotes, char argv)
{
	if ((argv == '\"' && quotes == 1) || \
					(argv == '\'' && quotes == 2))
		return (1);
	return (0);
}

char	**quotes_func(char **argv)
{
	int		i;
	int		j;
	int		quotes;
	char	**str;

	quotes = 0;
	i = 0;
	while (argv[i])
		i++;
	str = safe_alloc(1, sizeof(char *) * (i + 1));
	i = -1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			quotes = is_quotes_set(argv[i][j], quotes);
			if (quotes_func_len(quotes, argv[i][j]) == 1)
				str[i] = fts_strjoin(str[i], argv[i][j], 0);
			else if (argv[i][j] != '\"' && argv[i][j] != '\'')
				str[i] = fts_strjoin(str[i], argv[i][j], 0);
		}
	}
	str[i + 1] = NULL;
	return (str);
}
