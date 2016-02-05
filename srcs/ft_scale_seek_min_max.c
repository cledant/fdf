/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_seek_min_max.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 17:13:00 by cledant           #+#    #+#             */
/*   Updated: 2015/12/20 17:13:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static void	ft_x_scale(t_scale *scale, int i, int j, double x)
{
	if (x > scale->x_max)
	{
		scale->x_max = x;
		scale->x_max_x = i;
		scale->x_max_y = j;
	}
	if (x < scale->x_min)
	{
		scale->x_min = x;
		scale->x_min_x = i;
		scale->x_min_y = j;
	}
}

static void	ft_y_scale(t_scale *scale, int i, int j, double y)
{
	if (y > scale->y_max)
	{
		scale->y_max = y;
		scale->y_max_x = i;
		scale->y_max_y = j;
	}
	if (y < scale->y_min)
	{
		scale->y_min = y;
		scale->y_min_x = i;
		scale->y_min_y = j;
	}
}

static void	ft_z_scale(t_scale *scale, int i, int j, int **tab)
{
	if (tab[j][i] > scale->z_max)
		scale->z_max = tab[j][i];
	if (tab[j][i] < scale->z_min)
		scale->z_min = tab[j][i];
}

void		ft_scale_seek_min_max(t_scale *scale, int **tab)
{
	int		i;
	int		j;
	double	x;
	double	y;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (j < scale->max_seek_y)
	{
		while (i < scale->max_seek_x)
		{
			x = ft_x_coord_real(i, j);
			y = ft_y_coord_real(tab[j][i], i, j);
			ft_x_scale(scale, i, j, x);
			ft_y_scale(scale, i, j, y);
			ft_z_scale(scale, i, j, tab);
			i++;
		}
		i = 0;
		j++;
	}
}
