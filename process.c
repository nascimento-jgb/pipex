/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:05:16 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/16 10:17:30 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command(char **paths, char *cmd)
{
	char *aux;
	char *command;

	while (*paths)
	{
		aux = ft_strjoin(*paths, "/");
		command = ft_strjoin(aux, cmd);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void first_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.pipe[1] , STDOUT_FILENO);
	close(pipex.pipe[0]);
	dup2(pipex.infile, STDIN_FILENO);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_command(pipex.cmd, pipex.cmd_args);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		error_messa();
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	return (EXIT_FAILURE);
}

void second_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.pipe[0], STDIN_FILENO);
	close(pipex.pipe[1]);
	dup2(pipex.outfile, STDOUT_FILENO);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_command(pipex.cmd, pipex.cmd_args);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		error_message();
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	return (EXIT_FAILURE);
}
