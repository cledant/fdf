/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:31:39 by cledant           #+#    #+#             */
/*   Updated: 2015/12/20 11:06:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	ft_scale_value(t_scale *scale, int **tab)
{
	while ((WIN_X - (WIN_X / 10)) > (abs(ft_x_coord_scaled(scale->x_max_x,
			scale->x_max_y, scale)) + abs(ft_x_coord_scaled(scale->x_min_x,
				scale->x_min_y, scale))) && (WIN_Y - (WIN_Y / 10)) >
					(abs(ft_y_coord_scaled(tab[scale->y_max_y][scale->y_max_x],
						scale->y_max_x, scale->y_max_y, scale) +
							abs(ft_y_coord_scaled(tab[scale->y_min_y]
								[scale->y_min_x], scale->y_min_x,
									scale->y_min_y, scale)))))
	{
		scale->value = scale->value + 0.1;
	}
	scale->value = scale->value - 0.1;
}
