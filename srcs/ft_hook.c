/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:27:39 by cledant           #+#    #+#             */
/*   Updated: 2015/12/20 14:16:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int		expose_hook(t_mlx *e)
{
	if (e->render != 1)
	{
		ft_mlx_i_draw_wireframe(e->img, e->tab, e->x_max, e->y_max);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		e->render = 1;
	}
	return (0);
}

int		key_hook(int keycode, t_mlx *e)
{
	if (keycode == e->key)
	{
		ft_memdel((void **)e->tab);
		mlx_destroy_image(e->mlx, e->img);
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	return (0);
}
