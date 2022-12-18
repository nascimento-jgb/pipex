/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:35:12 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/18 11:14:25 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

/* write, read, close, fork, pipe, acess, dup2, execve */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* waitpid, wait */
# include <sys/wait.h>

/* open, unlink */
# include <fcntl.h>

/* malloc, free, exit */
# include <stdlib.h>

/* perror */
# include <stdio.h>

# define ERROR_INFILE "Infile"
# define ERROR_OUTFILE "Outfile"
# define ERROR_INPUT "Invalid number of arguments.\n"
# define ERROR_PIPE "Pipe"
# define ERROR_CMD "Command not found.\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe[2];
	int		infile;
	int		outfile;
	char	*cmd;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
}	t_pipex;

void		close_pipes(t_pipex *pipex);
char		*check_path(char **envp);
static char	*get_command(char **paths, char *cmd);
void		first_child(t_pipex pipex, char **argv, char **envp);
void		second_child(t_pipex pipex, char **argv, char **envp);
void		error_message(char *error);
int			message(char *error);
void		free_child(t_pipex *pipex);
void		free_parent(t_pipex *pipex);

#endif
