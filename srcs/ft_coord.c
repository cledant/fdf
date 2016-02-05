/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:50:12 by cledant           #+#    #+#             */
/*   Updated: 2015/12/19 16:51:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int		ft_x_coord_scaled(int i, int j, t_scale *scale)
{
	double	x;
	int		x_round;

	x = (M_SQRT2 / 2) * (i - j) * scale->value + scale->dec_x;
	x_round = ft_round_double(x);
	return (x_round);
}

int		ft_y_coord_scaled(int z, int i, int j, t_scale *scale)
{
	double	y;
	int		y_round;

	z = -z;
	y = (((double)(-1) / sqrt(6)) * (-i - j) +
			sqrt((double)2 / 3) * (double)z * 0.35) * scale->value +
				scale->dec_y;
	y_round = ft_round_double(y);
	return (y_round);
}

double	ft_x_coord_real(int i, int j)
{
	double	x;

	x = (M_SQRT2 / 2) * (i - j);
	return (x);
}

double	ft_y_coord_real(int z, int i, int j)
{
	double	y;

	z = -z;
	y = (((double)(-1) / sqrt(6)) * (-i - j) +
			sqrt((double)2 / 3) * z * 0.35);
	return (y);
}

int		ft_round_double(double nb)
{
	int		nb_int;

	nb_int = (int)nb;
	if (ft_abs(nb_int - nb) >= 0.5)
		nb_int++;
	return (nb_int);
}
