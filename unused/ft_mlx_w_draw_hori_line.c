/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_w_draw_hori_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 14:05:56 by cledant           #+#    #+#             */
/*   Updated: 2015/12/19 20:48:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	ft_mlx_w_draw_hori_line(t_mlx *e, int *p1, int *p2)
{
	if (p2[0] - p1[0] > 0)
	{
		while (p1[0] < p2[0])
		{
			mlx_pixel_put(e->mlx, e->win, p1[0], p1[1], 0xFFFFFF);
			p1[0]++;
		}
		mlx_pixel_put(e->mlx, e->win, p2[0], p2[1], 0xFFFFFF);
	}
	else
	{
		while (p1[0] > p2[0])
		{
			mlx_pixel_put(e->mlx, e->win, p1[0], p1[1], 0xFFFFFF);
			p1[0]--;
		}
		mlx_pixel_put(e->mlx, e->win, p2[0], p2[1], 0xFFFFFF);
	}
}
