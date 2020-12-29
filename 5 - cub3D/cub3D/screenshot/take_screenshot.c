/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_screenshot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 22:00:25 by curreg            #+#    #+#             */
/*   Updated: 2020/10/20 18:01:59 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			get_color_scr(t_vars *vars, int x, int y)
{
	char *dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

static void	init_header(unsigned char *h_arr, int size, t_vars *vars, int temp)
{
	h_arr[0] = (unsigned char)'B';
	h_arr[1] = (unsigned char)'M';
	h_arr[2] = (unsigned char)size;
	h_arr[3] = (unsigned char)(size >> 8);
	h_arr[4] = (unsigned char)(size >> 16);
	h_arr[5] = (unsigned char)(size >> 24);
	h_arr[10] = (unsigned char)54;
	h_arr[14] = (unsigned char)40;
	h_arr[18] = (unsigned char)temp;
	h_arr[19] = (unsigned char)(temp >> 8);
	h_arr[20] = (unsigned char)(temp >> 16);
	h_arr[21] = (unsigned char)(temp >> 24);
	h_arr[22] = (unsigned char)vars->y_res;
	h_arr[23] = (unsigned char)(vars->y_res >> 8);
	h_arr[24] = (unsigned char)(vars->y_res >> 16);
	h_arr[25] = (unsigned char)(vars->y_res >> 24);
	h_arr[26] = (unsigned char)1;
	h_arr[28] = (unsigned char)24;
}

static void	get_screenshot(t_vars *vars, int fd, int res)
{
	int color;
	int x;
	int y;
	int size_x;

	color = 0;
	x = 0;
	y = vars->y_res - 1;
	size_x = res;
	while (y >= 0)
	{
		while (x < size_x)
		{
			color = get_color_scr(vars, x, y);
			write(fd, &color, 3);
			x++;
		}
		y--;
		x = 0;
	}
}

void		take_screenshot(t_vars *vars)
{
	int					fd;
	unsigned char		header_arr[54];
	int					count;
	int					size;
	int					temp_res;

	temp_res = vars->x_res;
	if (vars->x_res % 4)
		temp_res = vars->x_res - (vars->x_res % 4);
	size = temp_res * vars->y_res + 54;
	count = 0;
	fd = open("./screenshot.bmp", O_RDWR | O_CREAT, 0666);
	while (count < 54)
	{
		header_arr[count] = (unsigned char)0;
		count++;
	}
	init_header(header_arr, size, vars, temp_res);
	write(fd, header_arr, 54);
	get_screenshot(vars, fd, temp_res);
	close(fd);
	exit(0);
}
