/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:35:12 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/16 08:48:11 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* write, read, close, fork, pipe, acess, dup2, execve */
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

/* waitpid, wait */
#include <sys/wait.h>

/* open, unlink */
#include <fcntl.h>

/* malloc, free, exit */
#include <stdlib.h>

/* perror */
#include <stdio.h>

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

#endif
