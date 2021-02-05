/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:52:29 by curreg            #+#    #+#             */
/*   Updated: 2020/11/28 21:59:49 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	reset_g_error(void)
{
	g_error = 0;
}

void		set_g_error(int err)
{
	if (err == 2 || err == 20)
		g_error = 1;
	else if (err == 14)
		g_error = 127;
}

void		show_g_error(void)
{
	char *error;

	error = ft_itoa(g_error);
	ft_putstr_fd(error, 1);
	reset_g_error();
}
