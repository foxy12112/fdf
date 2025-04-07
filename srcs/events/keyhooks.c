/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:17:15 by ldick             #+#    #+#             */
/*   Updated: 2025/04/07 15:27:02 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_loop_hook(void *param)
{
	t_fdf *fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE) == true)
		clean_exit(fdf, fdf->rows);
}