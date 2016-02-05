/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:42:33 by cledant           #+#    #+#             */
/*   Updated: 2015/12/20 15:35:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"

static int		main_part1(t_mlx *e)
{
	e->mlx = mlx_init();
	if (e->mlx == NULL)
	{
		ft_putendl("Error");
		return (0);
	}
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "FdF");
	if (e->win == NULL)
	{
		ft_putendl("Error");
		return (0);
	}
	e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	if (e->img == NULL)
	{
		mlx_destroy_window(e->mlx, e->win);
		ft_putendl("Error");
		return (0);
	}
	return (1);
}

static int		main_part1_5(t_mlx *e, t_list *lst)
{
	int		**tab;

	tab = ft_fill_int_tab2(lst, e->x_max, e->y_max);
	if (tab == NULL)
	{
		ft_lstdel(&lst, &ft_bzero);
		ft_putendl("Error");
		return (0);
	}
	ft_lstdel(&lst, &ft_bzero);
	e->tab = tab;
	e->key = MLX_KEY_ESC;
	e->render = 0;
	return (1);
}

static int		main_part2(t_mlx *e, int fd, t_list *lst)
{
	if ((lst = ft_lstread_file(fd)) == NULL)
	{
		ft_putendl("Error");
		return (0);
	}
	if (ft_lstsplit_whitespaces_content(lst) == 0)
	{
		ft_lstdel(&lst, &ft_bzero);
		ft_putendl("Error");
		return (0);
	}
	e->y_max = ft_lstcount_node(lst);
	e->x_max = ft_lstseek_max_x(lst);
	if (e->x_max == 0 || (e->y_max == 1 && e->x_max == 1))
	{
		ft_putendl("Error");
		ft_lstdel(&lst, &ft_bzero);
		return (0);
	}
	if (main_part1_5(e, lst) == 0)
		return (0);
	return (1);
}

static void		ft_free_all(t_mlx *e)
{
	mlx_destroy_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img);
	ft_memdel((void **)e->tab);
}

int				main(int argc, char **argv)
{
	t_mlx		e;
	t_list		*lst;
	int			fd;

	lst = NULL;
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putendl("Error");
		return (0);
	}
	if (main_part1(&e) == 0)
		return (0);
	if ((main_part2(&e, fd, lst)) == 0)
		return (0);
	if (close(fd) == -1)
	{
		ft_free_all(&e);
		return (0);
	}
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
