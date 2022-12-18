/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:26:04 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/18 11:14:28 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_message(char *error)
{
	perror(error);
	exit(1);
}

int	message(char *error)
{
	write(2, error, ft_strlen(error));
	return (1);
}

void	free_child(t_pipex *pipex)
{
	int	j;

	j = 0;
	while (pipex->cmd_args[j])
	{
		free(pipex->cmd_args[j]);
		j++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	free_parent(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}
