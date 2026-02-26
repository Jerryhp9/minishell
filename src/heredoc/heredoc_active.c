/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_active.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:01:33 by jhor              #+#    #+#             */
/*   Updated: 2026/02/24 01:18:46 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	heredoc_ast(t_ast *root, t_globe *p)
{
	int		i;
	t_ast	*cur_cmd;

	i = 0;
	cur_cmd = NULL;
	if (root->children)
	{
		while (i < root->childcount && root->children[i])
		{
			cur_cmd = root->children[i];
			find_heredoc(cur_cmd, p);
			if (p->err_flag == 1)
				break ;
			i++;
		}
	}
}
