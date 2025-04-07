/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:48:20 by foxy12112         #+#    #+#             */
/*   Updated: 2025/04/07 15:27:26 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <limits.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../main-libs/libs.h"
#include "../MLX42/include/MLX42/MLX42.h"

#define MAX_WIDTH 100
#define WIDTH 1920
#define HEIGHT 1080

typedef struct	s_3d
{
	int			x;
	int			y;
	int			z;
	int			color_val;
	int			size;
}				t_3d;

typedef struct	s_fdf
{
	char		**map;
	int			rows;
	t_3d		**three_d;
	mlx_t		*mlx;
	mlx_image_t	*image;
}				t_fdf;

t_fdf			*parse(char *filename);
void			pretty_background(t_fdf *fdf);
int				rendering(t_fdf *fdf);
void			clean_exit(t_fdf *fdf, int row);
void			ft_loop_hook(void *param);
