/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:33:23 by curreg            #+#    #+#             */
/*   Updated: 2021/02/02 03:09:24 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./get_next_line/get_next_line.h"

int main()
{
    int fd;
	char *line;

	line = NULL;
	fd = open("./text.txt", O_RDONLY);
    while(get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	//getchar();
    return (0);
}