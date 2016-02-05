/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_w_draw_diag_line1234.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 14:01:41 by cledant           #+#    #+#             */
/*   Updated: 2015/12/19 20:47:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void		ft_mlx_w_draw_diag1_line(t_mlx *e, int *p1, int *p2)
{
	int		dx;
	int		dy;
	int		epsi;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	epsi = dx;
	dx = dx * 2;
	dy = dy * 2;
	while (p1[0] < p2[0])
	{
		mlx_pixel_put(e->mlx, e->win, p1[0], p1[1], 0xFFFFFF);
		epsi = epsi - dy;
		if (epsi < 0)
		{
			p1[1]++;
			epsi = epsi + dx;
		}
		p1[0]++;
	}
	mlx_pixel_put(e->mlx, e->win, p2[0], p2[1], 0xFFFFFF);
}

void		ft_mlx_w_draw_diag2_line(t_mlx *e, int *p1, int *p2)
{
	int		dx;
	int		dy;
	int		epsi;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	epsi = dy;
	dx = dx * 2;
	dy = dy * 2;
	while (p1[1] < p2[1])
	{
		mlx_pixel_put(e->mlx, e->win, p1[0], p1[1], 0xFFFFFF);
		epsi = epsi - dx;
		if (epsi < 0)
		{
			p1[0]++;
			epsi = epsi + dy;
		}
		p1[1]++;
	}
	mlx_pixel_put(e->mlx, e->win, p2[0], p2[1], 0xFFFFFF);
}

void		ft_mlx_w_draw_diag3_line(t_mlx *e, int *p1, int *p2)
{
	int		dx;
	int		dy;
	int		epsi;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	epsi = dy;
	dx = -dx * 2;
	dy = dy * 2;
	while (p1[1] < p2[1])
	{
		mlx_pixel_put(e->mlx, e->win, p1[0], p1[1], 0xFFFFFF);
		epsi = epsi - dx;
		if (epsi < 0)
		{
			p1[0]--;
			epsi = epsi + dy;
		}
		p1[1]++;
	}
	mlx_pixel_put(e->mlx, e->win, p2[0], p2[1], 0xFFFFFF);
}

void		ft_mlx_w_draw_diag4_line(t_mlx *e, int *p1, int *p2)
{
	int		dx;
	int		dy;
	int		epsi;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	epsi = -dx;
	dx = -dx * 2;
	dy = dy * 2;
	while (p1[0] > p2[0])
	{
		mlx_pixel_put(e->mlx, e->win, p1[0], p1[1], 0xFFFFFF);
		epsi = epsi - dy;
		if (epsi < 0)
		{
			p1[1]++;
			epsi = epsi + dx;
		}
		p1[0]--;
	}
	mlx_pixel_put(e->mlx, e->win, p2[0], p2[1], 0xFFFFFF);
}
