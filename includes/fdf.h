/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:30:54 by cledant           #+#    #+#             */
/*   Updated: 2015/12/20 14:47:36 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"
# define MLX_KEY_ESC 53
# define WIN_X 2000
# define WIN_Y 1000

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		render;
	int		key;
	void	*img;
	int		**tab;
	int		y_max;
	int		x_max;
}				t_mlx;

typedef struct	s_scale
{
	double	x_min;
	int		x_min_x;
	int		x_min_y;
	double	x_max;
	int		x_max_x;
	int		x_max_y;
	double	y_min;
	int		y_min_x;
	int		y_min_y;
	double	y_max;
	int		y_max_x;
	int		y_max_y;
	double	value;
	int		dec_x;
	int		dec_y;
	int		z_min;
	int		z_max;
	int		max_seek_x;
	int		max_seek_y;
	void	*ptr_img;
}				t_scale;

char			*ft_mlx_i_position_in_2d(void *img, int i, int j);
void			ft_mlx_i_pixel_put(void *img, int x, int y, int color);
int				ft_mlx_i_drawline(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_hori_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_verti_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag1_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag2_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag3_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag4_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag5_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag6_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag7_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag8_line(void *e, int *p1, int *p2, int color);
int				ft_mlx_i_draw_wireframe(void *img, int **tab, int x_max,
					int y_max);
int				expose_hook(t_mlx *e);
int				key_hook(int keycode, t_mlx *e);
int				**ft_int_tab2_new(size_t i, size_t j);
double			ft_x_coord_real(int i, int j);
double			ft_y_coord_real(int z, int i, int j);
int				ft_x_coord_scaled(int i, int j, t_scale *scale);
int				ft_y_coord_scaled(int z, int i, int j, t_scale *scale);
int				ft_round_double(double nb);
int				ft_can_be_atoi(char *c);
int				**ft_fill_int_tab2(t_list *list, int x, int y);
char			**ft_strsplit_allspace(char const *s);
t_list			*ft_lstread_file(int fd);
int				ft_lstsplit_whitespaces_content(t_list *list);
size_t			ft_lstcount_non_zero_size_node(t_list *list);
size_t			ft_lstcount_node(t_list *list);
size_t			ft_lstseek_max_x(t_list *list);
void			ft_scale_init(t_scale *scale, int x_max, int y_max, void *img);
void			ft_scale_seek_min_max(t_scale *scale, int **tab);
void			ft_scale_value(t_scale *scale, int **tab);
void			ft_scale_dec(t_scale *scale, int **tab);
int				ft_scale_z_based_color(int z, t_scale *scale);
int				ft_max(int i, int j);

#endif
