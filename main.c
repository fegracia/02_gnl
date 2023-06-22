/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracia <fgracia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:26:12 by fgracia           #+#    #+#             */
/*   Updated: 2023/06/21 22:29:57 by fgracia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}

/* MODELO DE MAIN (1ª VERSÃO)
int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("file.txt", O_RDONLY);
	if (fd < -1)
	{
		printf("Não foi possível abrir o arquivo\n");
		return (1);
	}
	buffer = (char *)1;
	while (buffer != NULL)
	{
		buffer = get_next_line(fd);
		printf("Linha lida: %s", buffer);
	}
	close(fd);
	return (0);
}
*/

/* MODELO USANDO FUNÇÕES NATIVAS (READ)
int main()
{
    int fd;
	char buffer[256];
    int chars_read;

    fd = open("file.txt", O_RDONLY);

    if (!fd)
    {
        printf("Erro ao abrir o arquivo\n");
        return (1);
    }

    while ((chars_read = read(fd, buffer, 25)))
    {
		buffer[chars_read] = '\0';
	    printf("buf-> %s\n", buffer);
    }
    return (0);
}
*/
