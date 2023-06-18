/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracia <fgracia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:26:12 by fgracia           #+#    #+#             */
/*   Updated: 2023/06/17 23:05:24 by fgracia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    int fd;
    char *row;

    fd = open("file.txt", O_RDONLY);

    if (fd < -1)
    {
        printf("Erro ao abrir o arquivo\n");
        return (1);
    }

    while ((row = get_next_line(fd)) != NULL)
    {
        printf("Linha lida: %s", row);
        free(row);
    }
    close(fd);
    return 0;
}