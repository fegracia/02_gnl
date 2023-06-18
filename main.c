/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracia <fgracia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:26:12 by fgracia           #+#    #+#             */
/*   Updated: 2023/06/09 16:32:02 by fgracia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);

    if (fd < -1)
    {
        printf("Erro ao abrir o arquivo\n");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Linha lida: %s", line);
        free(line);
    }
    close(fd);
    return 0;
}