/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foxy12112 <foxy12112@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:01:44 by foxy12112         #+#    #+#             */
/*   Updated: 2025/04/06 20:25:33 by foxy12112        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calc_dot_dist_x(t_fdf *fdf)
{
	int amount = fdf->three_d[0][0].size;
	int distance = WIDTH / amount;
	return (distance);
}


int	calc_dot_dist_y(t_fdf *fdf)
{
	int amount = fdf->rows;
	int distance = HEIGHT / amount;
	return (distance);
}

void	draw_dots(t_fdf *fdf, int dist_x, int dist_y)
{
	for(int i = 0; i < WIDTH; i += dist_x)
	{
		for(int j = 0; j < HEIGHT; j += dist_y)
		{
			if (i < WIDTH || j < HEIGHT)
				break ;
			mlx_put_pixel(fdf->image, i, j, 0xFF0000);
		}
	}
}

int	rendering(t_fdf *fdf)
{
	int x_dist = calc_dot_dist(fdf);
	int y_dist = calc_dot_dist_y(fdf);
	draw_dots(fdf, x_dist, y_dist);
}