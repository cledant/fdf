/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_z_based_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 17:13:22 by cledant           #+#    #+#             */
/*   Updated: 2015/12/20 17:13:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_scale_z_based_color(int z, t_scale *scale)
{
	if (z < 0)
		return (0x0000FF);
	else if (z >= 0 && z < (scale->z_max / 5))
		return (0xFFFF00);
	else if (z >= (scale->z_max / 5) && z < (2 * scale->z_max / 5))
		return (0x00FF00);
	else if (z >= (2 * scale->z_max / 5) && z < (3 * scale->z_max / 5))
		return (0xA52A2A);
	else if (z >= (3 * scale->z_max / 5) && z < (4 * scale->z_max / 5))
		return (0x808080);
	else
		return (0xFFFFFF);
}
