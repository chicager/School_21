/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_eof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:20:57 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/25 19:21:24 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_pipe_eof(void)
{
	int arr[2];

	pipe(arr);
	write(arr[1], "", 0);
	dup2(arr[0], 0);
	close(arr[1]);
}
