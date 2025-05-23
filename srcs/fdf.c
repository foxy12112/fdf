/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:32:50 by ldick             #+#    #+#             */
/*   Updated: 2025/04/07 15:39:06 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void leaks(void)
{
	system("leaks fdf");
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	t_fdf *fdf = parse(argv[1]);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, argv[1], false);
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fdf->mlx, fdf->image, 0, 0);
	pretty_background(fdf);
	rendering(fdf);
	mlx_loop_hook(fdf->mlx, &ft_loop_hook, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}