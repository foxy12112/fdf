/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foxy12112 <foxy12112@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:32:50 by ldick             #+#    #+#             */
/*   Updated: 2025/04/06 20:26:01 by foxy12112        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	t_fdf *fdf = parse(argv[1]);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, argv[1], false);
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fdf->mlx, fdf->image, 0, 0);
	rendering(fdf);
}