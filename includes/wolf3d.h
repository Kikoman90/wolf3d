/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:23:56 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/22 18:45:04 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <../libft/libft.h>
# include <mlx.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>

# define RED 0xFE0000
# define ORANGE 0xFE7700
# define BLUE 0x00B2FE
# define YELLOW 0xFEFE00
# define SKY 0x5AD4EC
# define GRAY 0x686868

# define WIN_W 800
# define WIN_H 800

# define KEYPRESS (2)
# define KEYPRESSMASK (1L << 0)

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
	int			xstep;
	int			ystep;
	double		xside_dist;
	double		yside_dist;
	double		xdelta_dist;
	double		ydelta_dist;
}				t_draw;

typedef struct	s_mlx
{
	int			nbl;
	int			bpp;
	int			size_line;
	int			endian;
	char		*d;
	char		**map;
	void		*mlx;
	void		*win;
	void		*img;
	double		dh;
	t_cam		cam;
	t_draw		draw;
	t_player	player;
}				t_mlx;

int				ft_instructions(void);
int				ft_checkchar(char *buf);
int				ft_player_init(t_mlx *mlx);
int				ft_linelen(char *buf, int k);
int				key_hook(int keycode, t_mlx *mlx);
void			ft_draw(t_mlx *mlx);
void			ft_raycast(t_mlx *mlx);
void			ft_put_pixel(t_mlx *mlx, int x, int y, int color);

#endif
