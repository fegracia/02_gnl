/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracia <fgracia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:01:56 by fgracia           #+#    #+#             */
/*   Updated: 2023/06/22 23:25:48 by fgracia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>

int	acha_barra_ene(char *buffer)
{
	int i;
	i = 0;

	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	printf("%i\n", i);
	}
	return (0);
}


char	*get_next_line(int fd)
{
	char	*buffer;
	char	*buffer2;
	int 	new_size;
	int i;
	i = 1;

	buffer = malloc(sizeof(char) * 10 + 1);
	if (!buffer)
		return (NULL);
	while (i != 0)
	{
		i = read(fd, buffer, 10);
		if (i == 0)
			break ;
		buffer[i] = '\0';
		new_size = acha_barra_ene(buffer);
		buffer2 = malloc(sizeof(char) * new_size + 1);
		strncpy(buffer2, buffer, new_size);
		printf("buff1 retornou isso: '%s'\n", buffer);
		printf("buff2 retornou isso: '%s'\n", buffer2);
	}
	return ("");
}





int main()
{
	int fd;
	fd = open("file.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}