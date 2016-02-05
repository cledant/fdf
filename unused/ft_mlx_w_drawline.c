/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_w_drawline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 12:12:28 by cledant           #+#    #+#             */
/*   Updated: 2015/12/14 14:01:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static void	ft_case1(t_mlx *e, int *p1, int *p2)
{
	int		dx;
	int		dy;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	if (dx > 0 && dy > 0)
	{
		if (dx >= dy)
			ft_mlx_w_draw_diag1_line(e, p1, p2);
		else
			ft_mlx_w_draw_diag2_line(e, p1, p2);
	}
	if (dx > 0 && dy < 0)
	{
		if (dx >= -dy)
			ft_mlx_w_draw_diag8_line(e, p1, p2);
		else
			ft_mlx_w_draw_diag7_line(e, p1, p2);
	}
}

static void	ft_case2(t_mlx *e, int *p1, int *p2)
{
	int		dx;
	int		dy;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	if (dx < 0 && dy > 0)
	{
		if (-dx >= dy)
			ft_mlx_w_draw_diag4_line(e, p1, p2);
		else
			ft_mlx_w_draw_diag3_line(e, p1, p2);
	}
	if (dx < 0 && dy < 0)
	{
		if (-dx >= -dy)
			ft_mlx_w_draw_diag5_line(e, p1, p2);
		else
			ft_mlx_w_draw_diag6_line(e, p1, p2);
	}
}

int			ft_mlx_w_drawline(t_mlx *e, int *p1, int *p2)
{
	int		dx;
	int		dy;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	if (dx != 0)
	{
		if (dy != 0)
		{
			ft_case1(e, p1, p2);
			ft_case2(e, p1, p2);
		}
		else
			ft_mlx_w_draw_hori_line(e, p1, p2);
	}
	else
		ft_mlx_w_draw_verti_line(e, p1, p2);
	return (0);
}
