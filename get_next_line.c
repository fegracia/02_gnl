/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracia <fgracia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:47:13 by cmiho-en          #+#    #+#             */
/*   Updated: 2023/06/21 22:28:52 by fgracia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*static char	*read_file(int fd, char *backup)
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
*/

static char	*read_file(int fd, char *backup)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while ((read_bytes > 0) && (!ft_strchr(backup, '\n')))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			break ;
		buffer[read_bytes] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	if (read_bytes < 0)
		return (NULL);
	else
		return (backup);
}

static char	*get_line(char *backup)
{
	size_t	i;
	size_t	count;
	char	*current_line;

	count = 0;
	i = 0;
	if (!*backup)
		return (NULL);
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	current_line = malloc(sizeof(char) * (i + 2));
	if (!current_line)
		return (NULL);
	while (count <= i)
	{
		current_line[count] = backup[count];
		count++;
	}
	count--;
	if (backup[count] == '\n')
		current_line[count] = '\n';
	count++;
	current_line[count] = '\0';
	return (current_line);
}

static char	*delete_line(char *backup)
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
	static char	*backup;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	backup = read_file(fd, backup);
	if (!backup)
		return (NULL);
	current_line = get_line(backup);
	backup = delete_line(backup);
	return (current_line);
}
