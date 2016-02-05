/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 19:57:37 by cledant           #+#    #+#             */
/*   Updated: 2015/12/19 16:56:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	ft_scale_dec(t_scale *scale, int **tab)
{
	scale->dec_x = (WIN_X / 20) + abs(ft_x_coord_scaled(scale->x_min_x,
						scale->x_min_y, scale));
	scale->dec_y = (WIN_Y / 20) + abs(ft_y_coord_scaled(tab[scale->y_min_y]
						[scale->y_min_x], scale->y_min_x, scale->y_min_y,
							scale));
}
