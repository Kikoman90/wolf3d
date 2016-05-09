/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 14:11:42 by fsidler           #+#    #+#             */
/*   Updated: 2016/05/09 17:14:36 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_rotate(int keycode, double tmp_dir, double tmp_plane, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 0)
	{
		mlx->player.xdir = mlx->player.xdir * cos(mlx->player.rtspd)
			- mlx->player.ydir * sin(mlx->player.rtspd);
		mlx->player.ydir = tmp_dir * sin(mlx->player.rtspd)
			+ mlx->player.ydir * cos(mlx->player.rtspd);
		mlx->cam.xplane = mlx->cam.xplane * cos(mlx->player.rtspd)
			- mlx->cam.yplane * sin(mlx->player.rtspd);
		mlx->cam.yplane = tmp_plane * sin(mlx->player.rtspd)
			+ mlx->cam.yplane * cos(mlx->player.rtspd);
	}
	if (keycode == 124 || keycode == 2)
	{
		mlx->player.xdir = mlx->player.xdir * cos(-mlx->player.rtspd)
			- mlx->player.ydir * sin(-mlx->player.rtspd);
		mlx->player.ydir = tmp_dir * sin(-mlx->player.rtspd)
			+ mlx->player.ydir * cos(-mlx->player.rtspd);
		mlx->cam.xplane = mlx->cam.xplane * cos(-mlx->player.rtspd)
			- mlx->cam.yplane * sin(-mlx->player.rtspd);
		mlx->cam.yplane = tmp_plane * sin(-mlx->player.rtspd)
			+ mlx->cam.yplane * cos(-mlx->player.rtspd);
	}
	return (0);
}

static int	ft_sprint(int keycode, t_mlx *mlx)
{
	if (keycode == 257)
	{
		if (mlx->player.sprint == 0)
		{
			mlx->player.mvspd = 0.4;
			mlx->player.sprint = 1;
		}
		else
		{
			mlx->player.mvspd = 0.2;
			mlx->player.sprint = 0;
		}
	}
	ft_draw(mlx);
	return (0);
}

int			key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 126 || keycode == 13)
	{
		if (mlx->map[(int)(mlx->player.xpos + mlx->player.xdir
					* mlx->player.mvspd)][(int)(mlx->player.ypos)] != '1')
			mlx->player.xpos += mlx->player.xdir * mlx->player.mvspd;
		if (mlx->map[(int)(mlx->player.xpos)][(int)(mlx->player.ypos
					+ mlx->player.ydir * mlx->player.mvspd)] != '1')
			mlx->player.ypos += mlx->player.ydir * mlx->player.mvspd;
	}
	if (keycode == 125 || keycode == 1)
	{
		if (mlx->map[(int)(mlx->player.xpos - mlx->player.xdir
					* mlx->player.mvspd)][(int)(mlx->player.ypos)] != '1')
			mlx->player.xpos -= mlx->player.xdir * mlx->player.mvspd;
		if (mlx->map[(int)(mlx->player.xpos)][(int)(mlx->player.ypos
					- mlx->player.ydir * mlx->player.mvspd)] != '1')
			mlx->player.ypos -= mlx->player.ydir * mlx->player.mvspd;
	}
	if (keycode == 78 || keycode == 27)
		mlx->dh = (mlx->dh < 120) ? mlx->dh + 0.5 : mlx->dh;
	if (keycode == 69 || keycode == 24)
		mlx->dh = (mlx->dh > 0.5) ? mlx->dh - 0.5 : mlx->dh;
	ft_rotate(keycode, mlx->player.xdir, mlx->cam.xplane, mlx);
	ft_sprint(keycode, mlx);
	return (0);
}
