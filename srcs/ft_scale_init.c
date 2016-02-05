/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 17:12:45 by cledant           #+#    #+#             */
/*   Updated: 2015/12/20 17:12:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scale_init(t_scale *scale, int x_max, int y_max, void *img)
{
	scale->x_min = 0;
	scale->x_min_x = 0;
	scale->x_min_y = 0;
	scale->x_max = 0;
	scale->x_max_x = 0;
	scale->x_max_y = 0;
	scale->y_min = 0;
	scale->y_min_x = 0;
	scale->y_min_y = 0;
	scale->y_max = 0;
	scale->y_max_x = 0;
	scale->y_max_y = 0;
	scale->value = 0;
	scale->dec_x = 0;
	scale->dec_y = 0;
	scale->z_min = 0;
	scale->z_max = 0;
	scale->max_seek_x = x_max;
	scale->max_seek_y = y_max;
	scale->ptr_img = img;
}
