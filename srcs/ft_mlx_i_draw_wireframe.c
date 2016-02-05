/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_i_draw_wireframe.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 10:47:01 by cledant           #+#    #+#             */
/*   Updated: 2015/12/20 16:51:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void	ft_iso_x(int *p1, int *p2, t_scale *scale, int **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < scale->max_seek_y)
	{
		while (i + 1 < scale->max_seek_x)
		{
			p1[0] = ft_x_coord_scaled(i, j, scale);
			p2[0] = ft_x_coord_scaled(i + 1, j, scale);
			p1[1] = ft_y_coord_scaled(tab[j][i], i, j, scale);
			p2[1] = ft_y_coord_scaled(tab[j][i + 1], i + 1, j, scale);
			if (tab[j][i + 1] != tab[j][i])
				ft_mlx_i_drawline(scale->ptr_img, p1, p2,
					ft_scale_z_based_color(ft_max(tab[j][i + 1],
							tab[j][i]), scale));
			else
				ft_mlx_i_drawline(scale->ptr_img, p1, p2,
						ft_scale_z_based_color(tab[j][i], scale));
			i++;
		}
		i = 0;
		j++;
	}
}

static void	ft_iso_y(int *p1, int *p2, t_scale *scale, int **tab)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < scale->max_seek_x)
	{
		while (j + 1 < scale->max_seek_y)
		{
			p1[0] = ft_x_coord_scaled(i, j, scale);
			p2[0] = ft_x_coord_scaled(i, j + 1, scale);
			p1[1] = ft_y_coord_scaled(tab[j][i], i, j, scale);
			p2[1] = ft_y_coord_scaled(tab[j + 1][i], i, j + 1, scale);
			if (tab[j + 1][i] != tab[j][i])
				ft_mlx_i_drawline(scale->ptr_img, p1, p2,
					ft_scale_z_based_color(ft_max(tab[j + 1][i],
							tab[j][i]), scale));
			else
				ft_mlx_i_drawline(scale->ptr_img, p1, p2,
						ft_scale_z_based_color(tab[j][i], scale));
			j++;
		}
		j = 0;
		i++;
	}
}

int			ft_mlx_i_draw_wireframe(void *img, int **tab, int x_max, int y_max)
{
	int		p1[2];
	int		p2[2];
	int		i;
	int		j;
	t_scale	scale;

	i = 0;
	j = 0;
	ft_bzero(p1, 2);
	ft_bzero(p2, 2);
	ft_scale_init(&scale, x_max, y_max, img);
	ft_scale_seek_min_max(&scale, tab);
	ft_scale_value(&scale, tab);
	if (scale.value == 0)
	{
		ft_putendl("Error");
		exit(0);
	}
	ft_scale_dec(&scale, tab);
	ft_iso_x(p1, p2, &scale, tab);
	ft_iso_y(p1, p2, &scale, tab);
	return (0);
}
