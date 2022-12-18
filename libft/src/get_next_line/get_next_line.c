/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:11:35 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/05 15:32:52 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_nextline(char *buff)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	aux = ft_calloc2((ft_strlen2(buff) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buff[i])
		aux[j++] = buff[i++];
	free(buff);
	return (aux);
}

char	*ft_readline(char *buff)
{
	char	*line;
	int		count;

	count = 0;
	if (!buff[count])
		return (NULL);
	while (buff[count] != '\n' && buff[count])
		count++;
	line = ft_calloc2(count + 2, sizeof(char));
	count = 0;
	while (buff[count] != '\n' && buff[count])
	{
		line[count] = buff[count];
		count++;
	}
	if (buff[count] == '\n' && buff[count])
		line[count++] = '\n';
	return (line);
}

char	*ft_join_n_free(char *stash, char *rbuff)
{
	char	*aux;

	aux = ft_strjoin2(stash, rbuff);
	free(stash);
	return (aux);
}

char	*file_read(int fd, char *stash)
{
	char	*read_buffer;
	int		bytes;

	if (!stash)
		stash = ft_calloc2(1, 1);
	read_buffer = ft_calloc2(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(read_buffer);
			return (NULL);
		}
		read_buffer[bytes] = 0;
		stash = ft_join_n_free(stash, read_buffer);
		if (ft_strchr2(read_buffer, '\n'))
			break ;
	}
	free(read_buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = file_read(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_readline(buff);
	buff = ft_nextline(buff);
	return (line);
}
