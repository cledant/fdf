/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_i_pixel_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 19:35:39 by cledant           #+#    #+#             */
/*   Updated: 2015/12/15 12:33:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	ft_mlx_i_pixel_put(void *img, int x, int y, int color)
{
	char *ptr_img;

	ptr_img = ft_mlx_i_position_in_2d(img, x, y);
	ft_memmove(ptr_img, &color, sizeof(int));
}
