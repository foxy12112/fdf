/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:01:44 by foxy12112         #+#    #+#             */
/*   Updated: 2025/04/07 16:12:16 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	draw_line_x(int x0, int y0, int x1, int y1, t_fdf *fdf)
// {
// 	int	dx = x1 - x0;
// 	int	dy = y1 - y0;
// 	int	step_x = (dx > 0) ? 1 : -1;
// 	int	step_y = (dy > 0) ? 1 : -1;
// 	dx = ft_abs(dx);
// 	dy = ft_abs(dy);
// 	int start_x = x0;
// 	int start_y = y0;
// 	int	p = 2 * dy - dx;
// 	int	i = 0;

// 	while (i <= dx)
// 	{
// 		mlx_put_pixel(fdf->image, x0 - 50, y0 - 50, 0x64);
// 		if (p >= 0)
// 		{
// 			y0 += step_y;
// 			p -= 2 * dx;
// 		}
// 		p += 2 * dy;
// 		x0 += step_x;
// 		i++;
// 	}
// 	double dlen = sqrt(pow(x0 - start_x, 2) + pow(y0 - start_y, 2));
// 	return (int)dlen;
// }

// int	draw_line_y(int x0, int y0, int x1, int y1, t_fdf *fdf)
// {
// 	int	dx = x1 - x0;
// 	int	dy = y1 - y0;
// 	int	dx_abs = ft_abs(dx);
// 	int	dy_abs = ft_abs(dy);
// 	int	start_x = x0;
// 	int	start_y = y0;
// 	int	step_x = (dx > 0) ? 1 : -1;
// 	int	step_y = (dy > 0) ? 1 : -1;
// 	int	p = 2 * dx_abs - dy_abs;
// 	int	i = 0;
// 	while (i <= dy_abs)
// 	{
// 		mlx_put_pixel(fdf->image, x0 - 50, y0 - 50, 0x64);
// 		if (p >= 0)
// 		{
// 			x0 += step_x;
// 			p -= 2 * dy_abs;
// 		}
// 		p += 2 * dx_abs;
// 		y0 += step_y;
// 		i++;
// 	}
// 	double dlen = sqrt(pow(x0 - start_x, 2) + pow(y0 - start_y, 2));
// 	// printf("%f\n", dlen);
// 	return (int)dlen;
// }

// void	draw_line(int x0, int y0, int x1, int y1, t_fdf *cub)
// {
// 	int dx = abs(x1 - x0);
// 	int dy = abs(y1 - y0);

// 	if (dx >= dy)
// 		draw_line_x(x0, y0, x1, y1, cub);
// 	else
// 		draw_line_y(x0, y0, x1, y1, cub);
// }

int	calc_dot_dist_x(t_fdf *fdf)
{
	int amount = fdf->three_d[0][0].size;
	int distance = (WIDTH - 50) / amount;
	return (distance);
}


int	calc_dot_dist_y(t_fdf *fdf)
{
	int amount = fdf->rows;
	int distance = (HEIGHT - 50) / amount;
	return (distance);
}

void	draw_squares(t_fdf *fdf, int x, int y, int color)
{
	for (int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			mlx_put_pixel(fdf->image, x + i, y + j, color);
}

void	draw_dots(t_fdf *fdf, int dist_x, int dist_y)
{
	int i = 0;
	int j = 0;
	int x = 50;
	int y = 50;
	(void)dist_y;
	(void)dist_x;
	while(x < fdf->mlx->width - 50)
	{
		while(y < fdf->mlx->height - 50)
		{
			if (j > fdf->three_d[0][0].size)
			{
				j = 0;
				i++;
			}
			if (y % dist_y == 0 || x % dist_x == 0)
				mlx_put_pixel(fdf->image, x, y, 0xffffffff);
			if (y % dist_y == 0 && x % dist_x == 0)
			{
				mlx_put_pixel(fdf->image, x, y, fdf->three_d[i][j].color_val);
				j++;
			}
			y++;
		}
		y = 50;
		x++;
	}
}

// void	connect_dots(t_fdf *fdf, int x_dist, int y_dist)
// {
	
// }

int	rendering(t_fdf *fdf)
{
	int x_dist = calc_dot_dist_x(fdf);
	int y_dist = calc_dot_dist_y(fdf);
	printf("x_dist = %d\t\ty_dist = %d", x_dist, y_dist);
	draw_dots(fdf, x_dist, y_dist);
	// connect_dots(fdf, x_dist, y_dist);
	return (1);
}

void	pretty_background(t_fdf *fdf)
{
	for(int x = 0; x < fdf->mlx->width; x++)
		for(int y = 0; y < fdf->mlx->height; y++)
			mlx_put_pixel(fdf->image, x, y, 0xff);
}