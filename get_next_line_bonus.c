/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiho-en <cmiho-en@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:47:32 by cmiho-en          #+#    #+#             */
/*   Updated: 2023/06/08 17:13:03 by cmiho-en         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_file(int fd, char *backup)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while ((!backup || !ft_strchr(backup, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			break ;
		buffer[bytes_read] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	if (bytes_read < 0)
		return (NULL);
	return (backup);
}

static char	*get_line(char *backup)
{
	size_t	i;
	size_t	count;
	char	*current_line;

	count = -1;
	i = 0;
	if (!*backup)
		return (NULL);
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	current_line = malloc(sizeof(char) * (i + 2));
	if (!current_line)
		return (NULL);
	while (++count <= i)
		current_line[count] = backup[count];
	count--;
	if (backup[count] == '\n')
		current_line[count] = '\n';
	count++;
	current_line[count] = '\0';
	return (current_line);
}

static char	*remove_line(char *backup)
{
	size_t	i;
	size_t	j;
	char	*new_backup;

	i = 0;
	j = 0;
	if (!backup)
		return (NULL);
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	new_backup = malloc((ft_strlen(backup) - i + 1) * sizeof(char));
	if (!new_backup)
		return (NULL);
	i++;
	while (backup[i])
		new_backup[j++] = backup[i++];
	new_backup[j] = '\0';
	free(backup);
	return (new_backup);
}

char	*get_next_line(int fd)
{
	static char	*fdescriptors[MAX_FD];
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) || fd > MAX_FD)
		return (NULL);
	fdescriptors[fd] = read_file(fd, fdescriptors[fd]);
	if (!fdescriptors[fd])
		return (NULL);
	current_line = get_line(fdescriptors[fd]);
	fdescriptors[fd] = remove_line(fdescriptors[fd]);
	return (current_line);
}
