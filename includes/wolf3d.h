/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:23:56 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/18 17:09:22 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <../libft/libft.h>
# include <mlx.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>

# define WIN_W 800
# define WIN_H 800

# define BUFF_SIZE 100

typedef struct	s_player
{
	double		xpos;
	double		ypos;
	double		xdir;
	double		ydir;
	double		mvspd;
	double		rtspd;
}				t_player;

typedef struct	s_cam
{
	double		x;
	double		xpos;
	double		ypos;
	double		xdir;
	double		ydir;
	double		xplane;
	double		yplane;
	double		wall_dist;
}				t_cam;

typedef struct	s_draw
{
	int			x;
	int			xmap;
	int			ymap;
	int			start;
	int			end;
	int			height;
	int			side;
	int			hit;
	int			color;
	int			xstep;
	int			ystep;
	double		xside_dist;
	double		yside_dist;
	double		xdelta_dist;
	double		ydelta_dist;
}				t_draw;

typedef struct	s_mlx
{
	int			bpp;
	int			size_line;
	int			endian;
	char		*d;
	char		**map;
	void		*mlx;
	void		*win;
	void		*img;
	t_cam		cam;
	t_draw		draw;
	t_player	player;
}				t_mlx;

int				ft_instructions(void);
int				ft_checkchar(char *buf);
int				ft_player_init(t_mlx *mlx);
int				ft_linelen(char *buf, int k);
void			ft_draw(t_mlx *mlx);

#endif
